#include <stdio.h>

int main(){
    int number ;
    int evenSum = 0;
    int oddSum = 0;


    while (number != 0){
        scanf("%d", &number);

        if(number % 2 == 0 ){
            evenSum += number;

        }
        else if (number % 2 !=0){
            oddSum += number;

        }
     
    }

    printf("Even Sum: %d\n",evenSum);
    printf("Odd Sum: %d\n",oddSum);
 

    
}