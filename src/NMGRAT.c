/*
 * NMGRAT.c
 *
 *  Created on: 10 Oct 2017
 *      Author: ghorton
 */


#include <stdio.h>
#include "config.h"
#include "db.h"

int main() {
	// Start by reading in the configuration file
	readconfig();
	char* dbhost = getdbhost();
	char* dbname = getdbname();
	char* dbuser = getdbuser();
	char* dbpass = getdbpass();

	dbconnect(dbhost,dbname,dbuser,dbpass);
}
