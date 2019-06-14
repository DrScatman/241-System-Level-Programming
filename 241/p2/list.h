#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define EMPTY	0
#define FULL 	10000
#define TRUE 1
#define FALSE 0

typedef enum{false,true} boolean;

typedef struct Node* LINK;
struct Node{
	char elem[256]; 
	int count;
	LINK next;
};

LINK makeEmpty ();
int isEmpty(LINK head);
int deleteFirst(LINK head, char** p);
int insertAsFirst(char d[], LINK head);
int search(char d[], LINK head);
void clear(LINK head);	
void showList(LINK head, FILE* outf);

void readF(FILE *inf, LINK list);

void checkId(char* token, LINK list);

int checkQ(char line[], int* st, int* en);

int skipWhitespace(char line[]);

void splitLine(char line[], LINK list);




