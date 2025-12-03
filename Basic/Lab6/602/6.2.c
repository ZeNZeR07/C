#include <stdio.h>

void swap_values(int *a, int *b);

int main(){
    int num1;
    int num2;
    int before1, before2;  

    printf("Enter value for Num1: ");
    scanf("%d", &num1);

    printf("Enter value for Num2: ");
    scanf("%d", &num2);

    before1 = num1;
    before2 = num2;

 
    swap_values(&num1, &num2);

    printf("\n--- SWAP FUNCTION REPORT ---\n");

    printf("Before Swap - Num1: %d, Num2: %d\n", before1, before2);
    printf("After  Swap - Num1: %d, Num2: %d\n", num1, num2);

    return 0;
}

void swap_values(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
