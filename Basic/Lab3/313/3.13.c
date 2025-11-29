#include <stdio.h>

int main() {
    char text[101];
    int countUpper = 0;
    int countLower = 0;
    int countDigit = 0;
    int countOther = 0;
    int i;

    if (scanf("%s", text) != 1) {
        return 1;
    }

    for (i = 0; text[i] != '\0'; i++) {

        if (text[i] >= 'A' && text[i] <= 'Z') {
            countUpper++;
        }
        else if (text[i] >= 'a' && text[i] <= 'z') {
            countLower++;
        }
        else if (text[i] >= '0' && text[i] <= '9') {
            countDigit++;
        }
        else {
            countOther++;
        }

    }

    printf("Uppercase: %d\n", countUpper);
    printf("Lowercase: %d\n", countLower);
    printf("Digits: %d\n", countDigit);
    printf("Special/Other: %d\n", countOther);

    return 0;
}
