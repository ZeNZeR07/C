#include <stdio.h>
#include <ctype.h>

int main() {
    char text[101];
    int countUpper = 0;
    int countLower = 0;
    int countDigit = 0;
    int countOther = 0;
    int i;

    if (fgets(text, sizeof(text), stdin) == NULL) {
        return 1;
    }

    for (i = 0; text[i] != '\0' && text[i] != '\n'; i++) {
        if (isupper((unsigned char)text[i])) {
            countUpper++;
        }
        else if (islower((unsigned char)text[i])) {
            countLower++;
        }
        else if (isdigit((unsigned char)text[i])) {
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
