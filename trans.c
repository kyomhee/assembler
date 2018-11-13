#include "myas.h"

int instr_trans(char *op, char *args, char* mcode)
{
	// check syntax 
	if(!is_valid(op, args)){
		printf("Error: %s %s is not valid\n", op, args);
		return 0;
	}

	int i;

	strcpy(mcode, "AB CD EF");

	for(i=0; i<strlen(args);i++)
		if(args[i]==',') break;

	else if(args[0]=='%' && args[i+1]=='%')
		strcpy(mcode,"89");
	else if(args[0]=='(' || args[0]=='-')
		if(args[i+1]=='%') strcpy(mcode,"8b");
	else if(args[0]=='$' && args[i+1]=='%') {
		if(args[i+3]=='a') strcpy(mcode,"b8");
		else if(args[i+3]=='c') strcpy(mcode,"b9");
		else if(args[i+3]=='d') {
			if(argis[i+4]=='x')  strcpy(mcode,"ba");
			else if(args[i+4]=='i') strcpy(mcode,"bf");
		}	
		else if(args[i+3]=='b') {
			if(args[i+4]=='x') strcpy(mcode,"bb");
			else if(args[i+4]=='p') strcpy(mcode,"bd");
		}
		else if(args[i+3]=='s') {
			if(args[i+4]=='p') strcpy(mcode,"bc");
			else if(args[i+4]=='i') strcpy(mcode,"be");
		}
	}
	if(args[0]=='0' && args[i+1]=='%')
		strcpy(mcode,"a1");
	if(args[0]=='%') 
		if(args[i+1]==')' || args[i+1]=='0' || args[i+1]=='-')
			strcpy(mcode,"a3");
	
	return 1;	
}
