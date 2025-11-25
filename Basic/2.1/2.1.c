#include <stdio.h>

int main() {
    int N;      
    int i;      

    printf("Enter Hello Count: ");
    scanf("%d", &N);

  
    for (i = 0; i < N; i++) {
        printf("Hello Loop!\n");
    }

    return 0;
}
