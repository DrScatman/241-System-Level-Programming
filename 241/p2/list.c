#include "list.h"

LINK makeEmpty ()
/* creates an empty list */
{
	LINK head = (LINK) malloc( sizeof (struct Node) );
	head->next = NULL;
	strcpy(head->elem,"");
	head->count = 0;
	return head;
}

int isEmpty(LINK head)    
/* returns true if the list is empty */
{
	return ( head->next == NULL );
}

int deleteFirst(LINK head, char** p)
/* removes the first element from the list and 
   returns true if the operation is done successfully */ 
{
	LINK temp;
	if ( isEmpty(head) )
		return FALSE;
	temp = head->next;
	*p = temp->elem;
	head->next = temp->next;
	free (temp);
	return TRUE;
}

int moveFront(char d[], LINK head)
/* moves the node with element d to the front of the list */
{
	// Holds deleted count
	int dCount;

	LINK curr = head->next;
	while ( curr != NULL ) {
		if(strcmp(curr->next->elem, d) == 0)
		{
			dCount = curr->next->count;			
			free(curr->next);
	
			curr->next = curr->next->next;

			if(insertAsFirst(d, head))
				head->next->count = dCount;
			return TRUE;
		}
		curr = curr->next;
	}
	return FALSE;
}

int insertAsFirst(char d[], LINK head)
/* inserts an element as the first of the list and
   returns true if the operation is done successfully */ 
{
	if(search(d, head)){
		if(strcmp(head->next->elem, d) != 0)
			moveFront(d, head);
		return TRUE;
	}
		
	LINK temp = (LINK) malloc (sizeof (struct Node));
	strcpy(temp->elem, d);
	(temp->count)++;
	temp->next = head->next;
	head->next = temp;
	return TRUE;
}

int search(char d[], LINK head)
/* Checks if element is already in the list 
   if it is it increments the count and returns true */ 
{
	LINK curr = head->next;
	while ( curr != NULL ) {
		if(strcmp(curr->elem, d) == 0)
		{
			(curr->count)++;
			return TRUE;
		}
		curr = curr->next;
	}
	return FALSE;
}

void clear(LINK head)	
/* makes the list empty */
{
	char* temp;
	while ( !isEmpty(head) )
		deleteFirst (head, &temp);
}

void showList(LINK head, FILE* outf)
/* displays all elements in the list */
{
	LINK curr = head->next;
	while ( curr != NULL ) {
		printf ("%s   %d\n", curr->elem, curr->count);
		fprintf(outf, "%s   %d\n", curr->elem, curr->count);
		curr = curr->next;
	}
}

