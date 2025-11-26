#include <stdio.h>

int main() {
    int N;               
    int countFizzBuzz = 0;
    int countFizz = 0;
    int countBuzz = 0;
    int countOther = 0;

    printf("Enter Count: ");
    if (scanf("%d", &N) != 1 || N < 1) {
        return 1;       
    }

 
    for (int i = 1; i <= N; i++) {

        if (i % 3 == 0 && i % 5 == 0) {
            countFizzBuzz++;
        } else if (i % 3 == 0) {
            countFizz++;
        } else if (i % 5 == 0) {
            countBuzz++;
        } else {
            countOther++;
        }
    }

    printf("Count FizzBuzz (by 15): %d\n", countFizzBuzz);
    printf("Count Fizz (by 3 only): %d\n", countFizz);
    printf("Count Buzz (by 5 only): %d\n", countBuzz);
    printf("Count Other: %d\n", countOther);

    return 0;
}
