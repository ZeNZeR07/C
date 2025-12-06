#include <stdio.h>

void getLineCount(int *lineCountPtr) {
    printf("Enter N: ");

    if (scanf("%d", lineCountPtr) != 1) {
        *lineCountPtr = 0;
    }
}

void printHelloLine(int lineIndex) {
    printf("[%d] Hello world\n", lineIndex);
}


void printUsingPointer(int lineCount, void (*printFunc)(int)) {
    for (int currentLine = 1; currentLine <= lineCount; currentLine++) {
        printFunc(currentLine);
    }
}

int main(void) {
    int lineCount = 0;

 
    getLineCount(&lineCount);


    if (lineCount <= 0) {
        printf("Invalid N. Program will exit.\n");
        return 1;
    }


    printUsingPointer(lineCount, printHelloLine);

    return 0;
}
