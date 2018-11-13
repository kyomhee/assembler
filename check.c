#include "myas.h"

int is_valid(char *op, char *args)
{
	//printf("if valid, return 1\n");
	//printf("otherwise, return 0\n");
	
	int i;

	for(i=0;i<strlen(args);i++)
		if(args[i]==',') break;

	if(args[0]=='0' || args[0]=='(' || args[0]=='-') {
		if(args[i+1]=='0' || args[i+1]=='(' || args[i+1]=='-')
			return 0;
	}
	else if(args[i+1]=='$')
		 return 0;
	else return 1;
}
