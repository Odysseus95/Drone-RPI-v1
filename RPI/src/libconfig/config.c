#include <stdio.h>
#include <stdlib.h>
#include "config.h"
#include <string.h>


//List where configuration is stored
ConfigList configList;

static ConfigList initList(char* option, char* argument) {
	ConfigList list=malloc(sizeof(ConfigList));
	if (list==NULL) {perror("malloc:failed to init list");exit(EXIT_FAILURE);};
	strcpy(list->option,option);
	strcpy(list->argument,argument);
	list->next=NULL;
	return list;		
}


static void add_head(ConfigList* plist,char option[],char argument[]) {
	Cell* newCell=malloc(sizeof(Cell));
	if (newCell==NULL) {perror("malloc:failed to init cell");exit(EXIT_FAILURE);};
	strcpy((*plist)->option,option);
	strcpy((*plist)->argument,argument);
	newCell->next=*plist;
	plist=&newCell;
}


static void free_head(ConfigList* plist){
	Cell* freeCell=*plist;
	plist=&(freeCell->next);
	free(freeCell);
}


static void free_list(ConfigList* plist){
	while (*plist !=NULL) {
		free_head(plist);
	}
}


void getConfig(char filepath[]) {
	FILE* configFile=fopen(filepath,"r");
	if(configFile==NULL) 
	{
		perror("getConfig.fopen");
		printf("Configuration file %s not found\n",filepath);
		exit(EXIT_FAILURE);
	}
	char option[100];
	char argument[100];
	fscanf(configFile,"%100s=%100s\n",option,argument);
	configList=initList(option,argument);
	while(fscanf(configFile,"%100s=%100s\n",option,argument)){
		add_head(&configList,option,argument);
	}	
}


void print_config(ConfigList list) {
	printf("----------------\nCONFIGURATION\n----------------\n");
	if (list != NULL) {
		Cell* cellAct=list;
		while(cellAct != NULL){
			printf("%s=>%s\n",cellAct->option,cellAct->argument);
			cellAct=cellAct->next;
		}
	}
}


void config(char option[]) {	
}














