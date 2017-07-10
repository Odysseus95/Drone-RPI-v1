/*-------------------------------------
Project : Drone
Module : Camera RPI
Author : Odysseus
Date : 09/07/2017
--------------------------------------*/



#include <stdio.h>
#include <stdlib.h>
#include "config.h"
#include <string.h>


//List where configuration is stored
static ConfigList configList;
//Configuration file pointer
static FILE* configFile;

static ConfigList initList(char option[], char argument[]) {
	ConfigList list=malloc(sizeof(*list));
	if (list==NULL) {perror("initList.malloc");exit(EXIT_FAILURE);};
	strcpy(list->option,option);
	strcpy(list->argument,argument);
	list->next=NULL;
	return list;		
}


static void add_head(ConfigList* plist,char option[],char argument[]) {
	Cell* newCell=malloc(sizeof(Cell));
	if (newCell==NULL) {perror("add_head.malloc");exit(EXIT_FAILURE);};
	strcpy(newCell->option,option);
	strcpy(newCell->argument,argument);
	newCell->next=*plist;
	*plist=newCell;
}


static void free_head(ConfigList* plist){
	Cell* freeCell=*plist;
	*plist=freeCell->next;
	free(freeCell);
}


static void free_list(ConfigList* plist){
	while (*plist !=NULL) {
		free_head(plist);
	}
}



//TODO prevent segfault with long string
void getConfig(char filepath[]) {
	configFile=NULL;
	configFile=fopen(filepath,"r");
	if(configFile==NULL) 
	{
		perror("getConfig.fopen");
		printf("Configuration file %s not found\n",filepath);
		exit(EXIT_FAILURE);
	}
	char option[100];
	char argument[100];
	fscanf(configFile,"%99s %99s\n",option,argument);
	configList=initList(option,argument);
	while(!feof(configFile)){
		fscanf(configFile,"%99s%99s\n",option,argument);
		add_head(&configList,option,argument);
	}	
}


void print_config() {
	printf("----------------\nCONFIGURATION\n----------------\n");
	Cell* cellAct=configList;
	while(cellAct != NULL){
		printf("%s=>%s\n",cellAct->option,cellAct->argument);
		cellAct=cellAct->next;
	}
}


void config_close() {
	if (configFile!=NULL) {
		free_list(&configList);
		fclose(configFile);
	}
}


char* config(char option[]) {	
	Cell* cellAct=configList;
	int found=0;
	char* res;
	while(cellAct!=NULL && !found) {
		if(strcmp(option,cellAct->option)==0) {
			res=cellAct->argument;
			found=1;
		}
		cellAct=cellAct->next;
	}	
	return res;
}


