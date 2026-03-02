#include <stdio.h>

long SumLoop( int targetNumber ) ;
long SumRecur( int targetNumber ) ;

int main() {
    int inputNumber = 10;

    printf("SumLoop(%d) = %ld\n", inputNumber, SumLoop(inputNumber));
    printf("SumRecur(%d) = %ld\n", inputNumber, SumRecur(inputNumber));

    return 0;
}


long SumLoop(int targetNumber) {
    long totalSum = 0;
    int counter;

    for (counter = 1; counter <= targetNumber; counter++) {
        totalSum = totalSum + counter;
    }

    return totalSum;
}

long SumRecur(int targetNumber) {
    if (targetNumber <= 1) {
        return targetNumber;
    }

    
    return targetNumber + SumRecur(targetNumber - 1);
}
