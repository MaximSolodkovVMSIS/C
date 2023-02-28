#include<stdio.h>
#include<stdlib.h>
#include<string.h>
enum VOLUME {
	SMALL = 4,
	AVERAGE = 8,
	BIG = 12,
	GRATE = 16
};
typedef enum VOLUME volume;
typedef struct machine {
	int fuel_tank_volume;
	volume engine_volume;
	int price;
	char* name;
} machine;