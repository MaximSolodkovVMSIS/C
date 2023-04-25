#include "function.h"

FILE* file_create(const char* file_name) {
    FILE* file = NULL;
    errno_t error;
    error = fopen_s(&file, file_name, "w");
    if (error != 0) {
        printf("\nFile open error\n");
        exit(-2);
    }
    return file;
}

FILE* file_open(const char* file_name) {
    FILE* file = NULL;
    errno_t error;
    error = fopen_s(&file, file_name, "r");
    if (error != 0) {
        return NULL;
    }
    return file;
}

char get_answer() {
    char answer = 0;
    while (scanf_s("%c", &answer, sizeof(answer)) == NULL || (answer != 'y' && answer != 'n') || getchar() != '\n') {
        printf("\nWrite your choice (y or n): ");
        rewind(stdin);
    }
    return answer;
}

char* input_str() {
    char* string = (char*)calloc(256, sizeof(char));
    gets_s(string, 256);
    int size = strlen(string);
    string = (char*)realloc(string, size + 1);
    return string;
}

void print_answer_menu() {
    printf("Write n - no or y - yes\n");
    printf("Your answer: ");
}

void game() {
    FILE* database_file = NULL;
    node* node_to_change = NULL;
    node* root = NULL;
    printf("It is Clash of Clans Akinator, let's play\n");
    if ((database_file = file_open("database.txt")) == NULL) {
        root = new_node("Barbarian");
    }
    else {
        root = load_database(database_file);
        fclose(database_file);
    }
    while (1) {
        node_to_change = traversal(root);
        if (node_to_change == NULL) {
            break;
        }
        add(node_to_change);
    }
    printf("\nCome back again\n");
    database_file = file_create("database.txt");
    push_database(database_file, root);
    fclose(database_file);
    free_tree(root);
}

node* new_node(const char* question) {
    node* tree_node = (node*)malloc(sizeof(node));
    tree_node->question = (char*)malloc(strlen(question) + 1);
    strcpy_s(tree_node->question, (strlen(question) + 1), question);
    tree_node->yes = NULL;
    tree_node->no = NULL;
    return tree_node;
}

void free_tree(node* root) {
    if (root == NULL) {
        return;
    }
    free_tree(root->yes);
    free_tree(root->no);
    if (root->question != NULL) {
        free(root->question);
    }
    free(root);
}

void free_node(node* tree_node) {
    free(tree_node->question);
    free(tree_node->yes);
    free(tree_node->no);
}

node* traversal(node* root) {
    char answer = NULL;
    if (root == NULL) {
        printf("Error");
        exit(-3);
    }
    printf("\n%s?\n", root->question);
    print_answer_menu();
    answer = get_answer();
    if (answer == YES) {
        if (root->yes == NULL) {
            printf("\nI guessed right!\n");
            return NULL;
        }
        else {
            return traversal(root->yes);
        }
    }
    else {
        if (root->no == NULL) {
            printf("\nI didn't guessed\n");
            return root;
        }
        else {
            return traversal(root->no);
        }
    }
    return NULL;
}

void add(node* node_to_change) {
    char answer = NULL;
    char* new_object_name = NULL;
    char* new_question = NULL;
    char* temp_string = NULL;
    node* new_question_node = NULL;
    node* new_object = NULL;
    if (node_to_change == NULL) {
        printf("Error");
        exit(-3);
    }
    printf("\nWhat is it?: ");
    new_object_name = input_str();
    printf("What is distinguishes %s from %s?: ", new_object_name, node_to_change->question);
    new_question = input_str();
    printf("What is answer for %s to \"%s\"?\n", new_object_name, new_question);
    print_answer_menu();
    answer = get_answer();
    new_object = new_node(new_object_name);
    new_question_node = new_node(new_question);
    if (answer == YES) {
        node_to_change->yes = new_object;
        node_to_change->no = new_question_node;
    }
    else {
        node_to_change->no = new_object;
        node_to_change->yes = new_question_node;
    }
    temp_string = node_to_change->question;
    node_to_change->question = new_question_node->question;
    new_question_node->question = temp_string;
    free(new_object_name);
    free(new_question);
}

void push_database(FILE* database_file, node* root) {
    if (root == NULL) {
        return;
    }
    if (root->yes == NULL && root->no == NULL) {
        fprintf(database_file, "%c", ANSWER);
        fprintf(database_file, "%s\n", root->question);
    }
    else {
        fprintf(database_file, "%c", QUESTION);
        fprintf(database_file, "%s\n", root->question);
    }
    push_database(database_file, root->yes);
    push_database(database_file, root->no);
}

void delete_symbol(char** string) {
    for (int i = 0; i < strlen((*string)); i++) {
        (*string)[i] = (*string)[i + 1];
    }
    (*string)[strcspn((*string), "\n")] = '\0';
}

node* load_database(FILE* database_file) {
    node* root = NULL;
    char* root_node = (char*)malloc(256);
    if (fgets(root_node, 256, database_file) == NULL) {
        free(root_node);
        return NULL;
    }
    if (root_node[0] == QUESTION) {
        delete_symbol(&root_node);
        root = new_node(root_node);
        root->yes = load_database(database_file);
        root->no = load_database(database_file);
    }
    else {
        delete_symbol(&root_node);
        return new_node(root_node);
    }
    free(root_node);
    return root;
}