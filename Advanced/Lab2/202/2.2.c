#include <stdio.h>


char *reverse(char str1[]);



int main() {
    char text[ 50 ] ;
    char *out ;


    if (fgets(text, sizeof(text), stdin) == NULL) {
        return 1;
    }

    *out = reverse(text);

    printf("%s", out);
    
}


char *reverse(char str1[]) {
    int i = 0;
    int j = 0;
    int temp[ 50 ];

  
    while (str1[i] != '\0') {
        i++;        
    }
    i--; 

   
    while (i >= 0) {
        temp[j] = str1[i];
        i--;
        j++;
    }
    return temp[j] = '\0';


}