/*
 * config.c
 *
 *  Created on: 10 Oct 2017
 *      Author: ghorton
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"
#include "db.h"

//char* CONFIGFILE "/etc/nmgrat/nmgrat.conf";
char* CONFIGFILE = "/tmp/nmgrat.conf";

char* dbhost;
char* dbname;
char* dbuser;
char* dbpass;

void readconfig(){

	FILE * fp;
	char * line = NULL;
	size_t len = 0;
	ssize_t read;

	fp = fopen(CONFIGFILE,"r");
	if(fp == NULL){
		printf("Unable to open file %s for reading",CONFIGFILE);
		exit(255);
	}

	while((read = getline(&line, &len, fp)) != -1){

		// Only care if string has some length
		if(read > 1){
			//skip anything with a #
			if(line[0] != '#'){
				char* data;
				char* key=NULL;
				char* value=NULL;
				data = strtok(line,"=");
				key = (char*) malloc((strlen(data)+1) * sizeof(char));
				strcpy(key,data);
				data = strtok(NULL,"=");
				value = (char*) malloc((strlen(data)+1) * sizeof(char));
				strcpy(value,data);

				if(value[strlen(value)-1] == '\n')
					value[strlen(value)-1] = 0;

				if(strcmp(key,"dbhost") == 0){
					dbhost = (char*) malloc((strlen(value)+1) * sizeof(char));
					strcpy(dbhost,value);
				} else if(strcmp(key,"dbname") == 0){
					dbname=(char*) malloc((strlen(value)+1) * sizeof(char));
					strcpy(dbname,value);
				} else if(strcmp(key,"dbuser") == 0){
					dbuser=(char*) malloc((strlen(value)+1) * sizeof(char));
					strcpy(dbuser,value);
				} else if (strcmp(key,"dbpass") == 0){
					dbpass=(char*) malloc((strlen(value)+1) * sizeof(char));
					strcpy(dbpass,value);
				}
			}
		}
	}

	fclose(fp);
	if(line)
		free(line);

}

char* getdbhost(){
	return dbhost;
}

char* getdbname(){
	return dbname;
}

char* getdbuser(){
	return dbuser;
}

char* getdbpass(){
	return dbpass;
}
