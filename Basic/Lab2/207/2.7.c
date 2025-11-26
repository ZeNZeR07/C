#include <stdio.h>

int main() {
    int N , i;
    int countFizzBuzz = 0;
    int countFizz = 0;
    int countBuzz = 0;
    int countOther = 0;

    printf("Enter Count : ");
    scanf("%d", &N);

    for ( int i = 0; i < N; i++ ){
      

        if (i % 3 == 0 && i % 5 == 0 ){
            countFizzBuzz++;

        }
        else if (i % 3 == 0){
            countFizz++;

        }
        else if (i % 5 == 0){
            countBuzz++;

        }
        else {
            countOther++;

        }

    }

    printf("Count FizzBuzz: %d\n", countFizzBuzz);
    printf("Count Fizz: %d\n", countFizz);
    printf("Count Buzz: %d\n", countBuzz);
    printf("Count Other: %d\n", countOther);

    return 0;
    
}
