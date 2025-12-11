#include <stdio.h>
#include <string.h>

char *reverse(char str1[]);

int main() {
    char text[50];
    char *out;

    fgets(text, sizeof(text), stdin);  

    out = reverse(text);   

    printf("%s\n", out); 

    return 0;
}

char *reverse(char str1[]) {
    static char str2[100];  
    int len = strlen(str1);
    int i;


    if (len > 0 && str1[len - 1] == '\n') {
        str1[len - 1] = '\0';
        len--;
    }

    for (i = 0; i < len; i++) {
        str2[i] = str1[len - 1 - i];
    }

    str2[len] = '\0';  
    return str2;
}