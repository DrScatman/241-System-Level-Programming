#include <stdio.h>
#include <ctype.h>

int main () {
char ch;
printf("Enter text (Ctrl-D to quit).\n");
while ( ch = getchar(), ch != EOF ) {
    if(isupper(ch)) {
        printf("%d\n", ch-'A');
    }
    else if(islower(ch)){
        printf("%d\n", ch-'a');
    }
    else{
        putchar(ch);
    }
}
return 0;
}
