#include <stdio.h>

int main() {
    int number;
    int evenSum = 0;
    int oddSum = 0;

    scanf("%d", &number);       

    while (number != 0) {      

        if (number % 2 == 0) {

            evenSum += number;

        }
         else {

            oddSum += number;

        }

        scanf("%d", &number);    
    }


    printf("Even Sum: %d\n", evenSum);
    printf("Odd Sum: %d\n", oddSum);

    return 0;


    
}
