#include "list.h"

int main(int argc, char* argv[]){
	LINK list = makeEmpty();

	FILE *inf, *outf;
	if (argc < 3) {
		printf ("Usage: prog_name infile outfile\n");
		exit(1);
	}


	inf = fopen(argv[1], "r");
	outf = fopen(argv[2], "w");

	if (inf ==  NULL || outf == NULL) 
	{
		printf("File could not be opened\n");
		exit(1);
	}	

	readF(inf, list);
	showList(list, outf);

	free(inf);
}

void readF(FILE *inf, LINK list){
	char line[1024];
	
	// Variables used for handling quotation marks
	char* nl;
	char* nl2;
	int st, en;

	while (fgets(line, sizeof line, inf) != NULL)
	{
		// Checks and handles comments
		if(line[skipWhitespace(line)] == '/'){
			continue;
		}

		// Checks and handles quotation marks
		if(checkQ(line, &st, &en)){
			nl = malloc(st * sizeof(char));
			memcpy(nl, &line[0], st);

			// Handles anything after quotations
			int len = strlen(line) - en;
			nl2 = malloc(len * sizeof(char));
			memcpy(nl2, &line[en], len); 

			strcpy(line, nl);
			splitLine(nl2, list);
		}

		splitLine(line, list);
	}
}

void splitLine(char line[], LINK list){
		char* token;
		char delimit[]=" ();:,.[]<>+=!-&|\t\r\n\v\f";

		// Gets the first word
		token = strtok(line, delimit);

		// Retrieves the rest of the words in file
		while(token != NULL)
		{
			// Extracts identifier and puts in list
			checkId(token, list);	
			token = strtok(NULL, delimit);
		}

}

int skipWhitespace(char line[]){
	size_t i = 0;
	while(line[i] == ' ' || line[i] == '\t'|| line[i] == '\n' || line[i] == '\r' || line[i] == '\f' || line[i] == '\v')
	{
		++i;
	}
	return i;
}

int checkQ(char line[], int* st, int* en)
	// find the start and end position of '"' in line and returns true if exists
{
	int c = 0;

	for(size_t i=0;i<strlen(line);i++)
	{
		if(line[i] == '"' && c == 0){
			*st = i;
			c = 1;
			continue;
		}
		if(line[i] == '"' && c == 1){
			*en = i;
			return TRUE;
		}
	}

	return FALSE;
}

void checkId(char* token, LINK list){
	// Ensures first char is alphanumeric or a underscore
	if(isalpha(token[0]) || token[0] == '_')
	{
		insertAsFirst(token, list);

	}
	// Checks for and handles dereference of identifier
	if(token[0] == '*' && (isalpha(token[1]) || token[1] == '_'))
	{
		char* nt;
		nt = malloc((strlen(token)-1) * sizeof(char));
		memcpy(nt, &token[1], (strlen(token)-1));
		insertAsFirst(nt, list);

	}
}
