#include <stdio.h>


void reverse(char str[], char str2[]);



int main() {
    char text[ 50 ];
    char out [ 50 ];


    if (fgets(text, sizeof(text), stdin) == NULL) {
        return 1;
    }

    reverse( text, out );

    printf("%s", out);
    
}


void reverse(char str[], char str2[]) {
    int i = 0;
    int j = 0;

  
    while (str[i] != '\0') {
        i++;        
    }
    i--; 

   
    while (i >= 0) {
        str2[j] = str[i];
        i--;
        j++;
    }
    str2[j] = '\0';


}