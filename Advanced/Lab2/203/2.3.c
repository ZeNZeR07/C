#include <stdio.h>
#include <string.h>

void explode(char str1[], char splitter, char str2[][10], int *count);

int main() {
    char out[20][10];
    int num = 0;
    int i;

   
    explode("I/Love/You", '/', out, &num);

    for (i = 0; i < num; i++) {
        printf("str2[%d] = \"%s\"\n", i, out[i]);
    }
    
    printf("count = %d\n", num);

    return 0;
}


void explode(char str1[], char splitter, char str2[][10], int *count) {
    int i = 0;        
    int j = 0;        
    *count = 0;

    while (str1[i] != '\0') {
        if (str1[i] == splitter) {
            str2[*count][j] = '\0';
            (*count)++;
            
            if (*count >= 20) return;
            j = 0;
        } else {
            if (j < 9) {
                str2[*count][j++] = str1[i];
            }
        }
        i++;
    }

  
    str2[*count][j] = '\0';
    (*count)++;
}