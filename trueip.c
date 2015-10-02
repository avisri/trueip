#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trueip.h"


char *inject_trueip(char *str)
{
	//const char* from = "Oct  2 14:16:20 sor-dash systemd: Starting Session 122 of user root.";
	const char* from = "Oct  2 14:16:20 sor-dash sshd[13950]: Accepted password for root from 172.20.20.4 port 50107 ssh2";
	char *tuple1 = (char*) malloc(17);
	char *tuple2 = (char*) malloc(32);
	char *tuple3 = (char*) malloc(strlen(from)-15);
	char *rtuple3 = (char*) malloc(strlen(from)-15);
	char *publicip = (char*) malloc(100);
	char *localip = (char*) malloc(100);
	char *rtext = (char*) malloc(100);

	strncpy(tuple1, from, 15);
	strncpy(tuple3, from+16, strlen(from)-16);
	sscanf(tuple3,"%s%*[^\n]",tuple2);
	strncpy(rtuple3, tuple3+14+strlen(tuple2), strlen(from)-strlen(tuple2)-16 );

	publicip = get_publicip();	
	localip = get_localip();	

	//printf("str1: %s|\n",tuple1);
	//printf("str2: %s|\n",tuple2);
	//printf("str3: %s|\n",rtuple3);
	sprintf(rtext,"%s %s[public=%s,%s] %s",tuple1,tuple2,publicip,localip,rtuple3);
	return rtext;
}

