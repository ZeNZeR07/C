#include <stdio.h>

void getN(int *pN) {
    printf("Enter N: ");
    scanf("%d", pN); 
}


void printLine(int index) {
    printf("[%d] Hello world\n", index);
}


void printUsingPointer(int n, void (*fp)(int)) {
    for(int i = 1; i <= n; i++) {
        fp(i);
    }
}

int main() {
    int n;

  
    getN(&n);

    printUsingPointer(n, printLine);

    return 0;
}
