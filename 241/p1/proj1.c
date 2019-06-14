#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// search the first n characters in array list for character target
// return true if it is found, and false otherwise
int found(char list[], int n, char target);

// initialize the encrypt array with appropriate cipher letters according to the given key
void initializeEncryptArray(char key[], char encrypt[]);

// initialize the decrypt array with appropriate substitute letters based on the encrypt array
void initializeDecryptArray(char encrypt[], char decrypt[]);

// process text from the input file and write the result to the output file
// pass the encrypt array to parameter substitute if encryption is intended
// pass the decrypt array to parameter substitute if decryption is intended
void processInput(FILE * inf, FILE * outf, char substitute[]);

char encrypt(char ch, char substitute[]);

char *strrev(char *str);

int main (int argc, char* argv[])
{
	int choice;
	char* key;
	char encrypt[27] = "";
	char decrypt[27] = "";
	FILE *inf, *outf;

	key = (char*)calloc(20, sizeof(char));
	if(key == NULL)
	{
		exit(1);
	}

	if (argc != 5)
	{
		printf ("Usage: cipher option key infile outfile\n");
		printf ("Option 1 for encryption and 2 for decryption");
		exit(1);
	}

	choice = atoi(argv[1]);
	key = argv[2];
	inf = fopen(argv[3], "r");
	outf = fopen(argv[4], "w");

	if (inf ==  NULL || outf == NULL) 
	{
		printf("File could not be opened\n");
		exit(1);
	}	

	if (choice == 2)
	{
		initializeEncryptArray(key, encrypt);
		initializeDecryptArray(encrypt, decrypt);
		processInput(inf, outf, decrypt);
	}
	else
	{
		initializeEncryptArray(key, encrypt);
		processInput(inf, outf, encrypt);
	}
	
	fclose(inf);
	fclose(outf);
	
	return 0;
}

char encrypt(char ch, char substitute[]){
	if (ch >='a' && ch <='z'){	
		int pos = ch - 97; 
        	return substitute[pos];
	}
	return ch;
}

// process text from the input file and write the result to the output file
// pass the encrypt array to parameter substitute if encryption is intended
// pass the decrypt array to parameter substitute if decryption is intended
void processInput(FILE * inf, FILE * outf, char substitute[])
{
	char id[1024];

	while (fscanf(inf, "%1023s", id) != EOF)
	{
		fprintf("%1023s", id);
	}
}

// initialize the encrypt array with appropriate cipher letters according to the given key
void initializeEncryptArray(char key[], char encrypt[])
{
	// Copy's each letter in array key into array
	// list if it is not found there 
	// Use variable size to keep track of the number of letters copied 
	
	int size = 0;
	int len = strlen(key);

	for(int i = 0; i < len; i++){
		if(!found(encrypt, size, key[i])){
			encrypt[size] = key[i];
			size++;
		}	
	}

	// Fills up the rest of array list with 
	// other letters in the alphabet in reverse order 
	
	for(int i = 0; size < 26; i++){
		if(!found(encrypt, size, ('z' - i))){
			encrypt[size] = 'z' - i;
			size++;
		}
	}
	encrypt[26] = '\0';
}

// initialize the decrypt array with appropriate substitute letters based on the encrypt array
void initializeDecryptArray(char encrypt[], char decrypt[])
{
	for(int i = 0; i < strlen(encrypt); i++){
		decrypt[encrypt[i] - 97] = i + 'a';
	}
}

// search the first n characters in array list for character target
// return true if it is found, and false otherwise
int found(char list[], int n, char target) 
{
	for (int i=0; i<n; i++){
		if (list[i] == target){
	     		return 1;
		}
	}
	return 0;
}