#include <stdio.h>

void increase_value(int *number_ptr);


int main(){
    int data;


    printf("Enter initial integer value: ");
    scanf("%d", &data);

    printf("\n--- POINTER MODIFICATION REPORT ---\n");
    printf("1. Value BEFORE function call : %d\n", data);

    increase_value(&data);

    return 0;

}

void increase_value(int *number_ptr){
    *number_ptr = *number_ptr + 10;
    printf("2. Value AFTER function call  : %d\n", *number_ptr);
}