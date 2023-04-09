#include "function.h"
void get_input_file_name(char* input_file_name) {
    printf("Enter the input file: ");
    fgets(input_file_name, 256, stdin);
    input_file_name[strlen(input_file_name) - 1] = '\0';
}
FILE* open_input_file(const char* file_name) {
    FILE* input_file;
    errno_t err = fopen_s(&input_file, file_name, "rb");
    if (err != 0) {
        printf("Error opening input file\n");
        return NULL;
    }
    return input_file;
}
void get_output_file_name_BW(char* output_file_name) {
    printf("Enter the name of output BW file: ");
    fgets(output_file_name, 256, stdin);
    output_file_name[strlen(output_file_name) - 1] = '\0';
}
void get_output_file_name_neg(char* output_file_name) {
    printf("Enter the name of output negative file: ");
    fgets(output_file_name, 256, stdin);
    output_file_name[strlen(output_file_name) - 1] = '\0';
}
void get_output_file_name_gamma(char* output_file_name) {
    printf("Enter the name of output gamma file: ");
    fgets(output_file_name, 256, stdin);
    output_file_name[strlen(output_file_name) - 1] = '\0';
}
void get_output_filename_median(char* output_file_name) {
    printf("Enter the name of output median file: ");
    fgets(output_file_name, 256, stdin);
    output_file_name[strlen(output_file_name) - 1] = '\0';
}
FILE* open_file(char* file_name, char* mode) {
    FILE* file;
    errno_t err = fopen_s(&file, file_name, mode);
    if (err != 0) {
        printf("Error opening file %s\n", file_name);
        return NULL;
    }
    return file;
}
void convert_file_in_bw(FILE* input_file, FILE* output_file, BMPFileHeader header) {
    fseek(input_file, header.bmpHeader.offset, SEEK_SET);
    fseek(output_file, header.bmpHeader.offset, SEEK_SET);
    for (int i = 0; i < header.dibHeader.imageSize; i += 3) {
        Pixel pixel;
        fread(&pixel, sizeof(Pixel), 1, input_file);

        char gray = (char)(0.3 * pixel.red + 0.59 * pixel.green + 0.11 * pixel.blue);

        Pixel gray_pixel = { gray, gray, gray };
        fwrite(&gray_pixel, sizeof(Pixel), 1, output_file);
    }
}
void convert_file_in_neg(FILE* input_file, FILE* output_file, BMPFileHeader header) {
    fseek(input_file, header.bmpHeader.offset, SEEK_SET);
    fseek(output_file, header.bmpHeader.offset, SEEK_SET);
    for (int i = 0; i < header.dibHeader.imageSize; i += 3) {
        Pixel pixel;
        fread(&pixel.blue, sizeof(unsigned char), 1, input_file);
        fread(&pixel.green, sizeof(unsigned char), 1, input_file);
        fread(&pixel.red, sizeof(unsigned char), 1, input_file);

        pixel.blue = (unsigned char)(255 - pixel.blue);
        pixel.green = (unsigned char)(255 - pixel.green);
        pixel.red = (unsigned char)(255 - pixel.red);


        fwrite(&pixel.blue, sizeof(unsigned char), 1, output_file);
        fwrite(&pixel.green, sizeof(unsigned char), 1, output_file);
        fwrite(&pixel.red, sizeof(unsigned char), 1, output_file);

    }
}
void gamma_correction(char* input_file, char* output_file, BMPFileHeader header, double gamma) {
    fseek(input_file, header.bmpHeader.offset, SEEK_SET);
    fseek(output_file, header.bmpHeader.offset, SEEK_SET);
    for (int i = 0; i < header.dibHeader.imageSize; i += 3) {
        Pixel pixel;
        fread(&pixel.blue, sizeof(unsigned char), 1, input_file);
        fread(&pixel.green, sizeof(unsigned char), 1, input_file);
        fread(&pixel.red, sizeof(unsigned char), 1, input_file);

        pixel.blue = (unsigned char)(pow((double)pixel.blue / 255.0, gamma) * 255.0);
        pixel.green = (unsigned char)(pow((double)pixel.green / 255.0, gamma) * 255.0);
        pixel.red = (unsigned char)(pow((double)pixel.red / 255.0, gamma) * 255.0);

        fwrite(&pixel.blue, sizeof(unsigned char), 1, output_file);
        fwrite(&pixel.green, sizeof(unsigned char), 1, output_file);
        fwrite(&pixel.red, sizeof(unsigned char), 1, output_file);
    }
}
int compare(const void* a, const void* b) {
    return (*(unsigned char*)a - *(unsigned char*)b);
}

void median_filter(char* input_file, char* output_file, int median, BMPFileHeader header) {
    // Запись заголовка BMP-файла в выходной файл
    fwrite(&header, sizeof(header), 1, output_file);
    // Переход к началу пикселей изображения в исходном и выходном файлах
    fseek(input_file, header.bmpHeader.offset, SEEK_SET);
    fseek(output_file, header.bmpHeader.offset, SEEK_SET);
    // Создание двумерного массива для хранения пикселей
    Pixel** pixels = (Pixel**)malloc(header.dibHeader.height * sizeof(Pixel*));
    for (int i = 0; i < header.dibHeader.height; i++) {
        pixels[i] = (Pixel*)malloc(header.dibHeader.width * sizeof(Pixel));
    }
    // Чтение данных пикселей изображения из входного файла
    for (int i = header.dibHeader.height - 1; i >= 0; i--) {
        for (int j = 0; j < header.dibHeader.width; j++) {
            fread(&pixels[i][j].blue, sizeof(unsigned char), 1, input_file);
            fread(&pixels[i][j].green, sizeof(unsigned char), 1, input_file);
            fread(&pixels[i][j].red, sizeof(unsigned char), 1, input_file);
        }
        fseek(input_file, header.dibHeader.width % 4, SEEK_CUR);
    }
    // Медианная фильтрация
    int halfFilterSize = median / 2;
    unsigned char* blueValues = NULL;
    unsigned char* greenValues = NULL;
    unsigned char* redValues = NULL;
    for (int i = halfFilterSize; i < header.dibHeader.height - halfFilterSize; i++) {
        blueValues = malloc(median * median * sizeof(unsigned char));
        greenValues = malloc(median * median * sizeof(unsigned char));
        redValues = malloc(median * median * sizeof(unsigned char));
        for (int j = halfFilterSize; j < header.dibHeader.width - halfFilterSize; j++) {
            int index = 0;

            for (int k = 0; k < median; k++) {
                for (int l = 0; l < median; l++) {
                    if (index < median * median) {
                        blueValues[index] = pixels[i + k - halfFilterSize][j + l - halfFilterSize].blue;
                        greenValues[index] = pixels[i + k - halfFilterSize][j + l - halfFilterSize].green;
                        redValues[index] = pixels[i + k - halfFilterSize][j + l - halfFilterSize].red;
                        index++;
                    }
                }
            }

            qsort(blueValues, median * median, sizeof(unsigned char), compare);
            qsort(greenValues, median * median, sizeof(unsigned char), compare);
            qsort(redValues, median * median, sizeof(unsigned char), compare);

            pixels[i][j].blue = blueValues[(median * median) / 2];
            pixels[i][j].green = greenValues[(median * median) / 2];
            pixels[i][j].red = redValues[(median * median) / 2];

        }
    }
    free(blueValues);
    free(greenValues);
    free(redValues);
    // Запись данных пикселей изображения в выходной файл
    for (int i = header.dibHeader.height - 1; i >= 0; i--) {
        for (int j = 0; j < header.dibHeader.width; j++) {
            fwrite(&pixels[i][j].blue, sizeof(unsigned char), 1, output_file);
            fwrite(&pixels[i][j].green, sizeof(unsigned char), 1, output_file);
            fwrite(&pixels[i][j].red, sizeof(unsigned char), 1, output_file);
        }
        if (header.dibHeader.height > header.dibHeader.width) {
            unsigned char padding = 0;
            fwrite(&padding, sizeof(unsigned char), header.dibHeader.width % 4, output_file);
        }
        //Этот цикл проходит по всем пикселям изображения в двумерном массиве pixels, начиная с нижней строки(последней) и заканчивая верхней строкой(первой)
        //Для каждого пикселя он записывает его цветовые компоненты в выходной файл, используя функцию fwrite
        //После записи каждой строки в файл, он добавляет нулевые байты(padding) до ближайшего кратного 4 - м количества байтов в строке
        // Это необходимо для того, чтобы длина каждой строки была кратной 4 - м байтам, как требуется форматом BMP

    }
    // Закрытие файлов и освобождение памяти

    for (int i = 0; i < header.dibHeader.height; i++) {
        free(pixels[i]);
    }
    free(pixels);
}

void remove_file(char* filename) {
    int status = remove(filename);
    if (status == 0) {
        printf("File %s deleted successfully.\n", filename);
    }
    else {
        printf("Unable to delete the file %s\n", filename);
    }
}

void show_menu() {
    printf("Select an option:\n");
    printf("1. Convert to black and white\n");
    printf("2. Convert to negative\n");
    printf("3. Gamma corrction \n");
    printf("4. Median filter\n");
    printf("5. Delete file\n");
    printf("6. Exit\n");
}

int get_menu_choice() {
    int choice;
    printf("Enter your choice: ");
    scanf_s("%d", &choice);
    getchar(); // отбрасывает символ новой строки, чтобы он не мешал последующим операциям ввода.
    return choice;
}
int menu() {
    char input_file_name[256];
    get_input_file_name(input_file_name);
    FILE* input_image_file = open_input_file(input_file_name);
    if (!input_image_file) {
        return 1;
    }
    BMPFileHeader header;
    fread(&header, sizeof(BMPFileHeader), 1, input_image_file);
    int choice;
    do {
        show_menu();
        choice = get_menu_choice();

        char output_file_name[256];
        char file_for_delete[256];
        FILE* output_file;
        switch (choice) {
        case 1:
            get_output_file_name_BW(output_file_name);
            output_file = open_file(output_file_name, "wb");
            if (!output_file) {
                fclose(input_image_file);
                return 1;
            }
            fwrite(&header, sizeof(BMPFileHeader), 1, output_file);
            convert_file_in_bw(input_image_file, output_file, header);
            fclose(output_file);
            break;
        case 2:
            get_output_file_name_neg(output_file_name);
            output_file = open_file(output_file_name, "wb");
            if (!output_file) {
                fclose(input_image_file);
                return 1;
            }
            fwrite(&header, sizeof(BMPFileHeader), 1, output_file);
            convert_file_in_neg(input_image_file, output_file, header);
            fclose(output_file);
            break;
        case 3:
            get_output_file_name_gamma(output_file_name);
            output_file = open_file(output_file_name, "wb");
            if (!output_file) {
                fclose(input_image_file);
                return 1;
            }
            fwrite(&header, sizeof(BMPFileHeader), 1, output_file);
            double gamma = 0;
            printf("Enter gamma: ");
            scanf_s("%lf", &gamma);
            gamma_correction(input_image_file, output_file, header, gamma);
            fclose(output_file);
            break;
        case 4:
            get_output_filename_median(output_file_name);
            output_file = open_file(output_file_name, "wb");
            if (!output_file) {
                fclose(input_image_file);
                return 1;
            }
            fwrite(&header, sizeof(BMPFileHeader), 1, output_file);
            int median = 0;
            printf("Enter median: ");
            scanf_s("%d", &median);
            median_filter(input_image_file, output_file, median, header);
            fclose(output_file);
            break;
        case 5:
            printf("Enter the name of the file to delete: ");
            fgets(file_for_delete, 256, stdin);
            // Заменяем символ перевода строки на нулевой символ
            file_for_delete[strcspn(file_for_delete, "\n")] = '\0';
            remove_file(file_for_delete);
            break;
        case 6:
            break;
        default:
            printf("Choice is uncorrect\n");
            break;
        }
    } while (choice != 6);
    fclose(input_image_file);
    return 0;
}
