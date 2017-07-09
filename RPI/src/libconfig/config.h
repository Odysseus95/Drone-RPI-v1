#ifndef _CONFIG_
#define _CONFIG_



typedef struct Cell Cell;
struct Cell {
	char option[100];
	char argument[100];
	Cell* next;
};

typedef Cell* ConfigList;



void getConfig(char filepath[]);
void print_config(ConfigList list);
void config(char option[]);	

#endif
