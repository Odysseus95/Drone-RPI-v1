/*-------------------------------------
Project : Drone
Module : Camera RPI
Author : Odysseus
Date : 09/07/2017
--------------------------------------*/

//TODO find memory leak


#include <stdio.h>
#include <stdlib.h>
#include "config.h"
#include <string.h>


//List where configuration is stored
static ConfigList configList;

static ConfigList initList(char* option, char* argument) {
	ConfigList list=malloc(sizeof(ConfigList));
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
	free(plist);
}



//TODO prevent segfault with long string
void getConfig(char filepath[]) {
	FILE* configFile=NULL;
	configFile=fopen(filepath,"r");
	if(configFile==NULL) 
	{
		perror("getConfig.fopen");
		printf("Configuration file %s not found\n",filepath);
		exit(EXIT_FAILURE);
	}
	char option[100];
	char argument[100];
	fscanf(configFile,"%100s %100s\n",option,argument);
	configList=initList(option,argument);
	while(!feof(configFile)){
		fscanf(configFile,"%100s %100s\n",option,argument);
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
	free_list(&configList);
}


void config(char option[]) {	
}














