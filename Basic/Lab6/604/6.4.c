#include <stdio.h>

void calculate_sum_product(int num, int num2, int *sum_ptr, int *prod_ptr);

int main(void) {
    int val_A, val_B;
    int result_sum;
    int result_product;

    printf("Enter first integer (Val A): ");
    scanf("%d", &val_A);

    printf("Enter second integer (Val B): ");
    scanf("%d", &val_B);

    calculate_sum_product(val_A, val_B, &result_sum, &result_product);

    printf("\n--- CALCULATION REPORT ---\n");
    printf("Input Values: A = %d, B = %d\n", val_A, val_B);
    printf("---------------------------\n");
    printf("Result Sum (A + B): %d\n", result_sum);
    printf("Result Product (A * B): %d\n", result_product);

    return 0;
}

void calculate_sum_product(int num, int num2, int *sum_ptr, int *prod_ptr) {
    *sum_ptr = num + num2;
    *prod_ptr = num * num2;
}
