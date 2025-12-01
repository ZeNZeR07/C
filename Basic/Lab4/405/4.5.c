#include <stdio.h>

#define SIZE 6

int main(void) {
    int data[SIZE];
    int total_sum = 0;
    int i;

    for (i = 0; i < SIZE; i++) {
        scanf("%d", &data[i]);
        total_sum += data[i];
    }

    printf("--- SUMMATION REPORT ---\n");
    printf("Recorded Numbers: ");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    printf("Total Sum of Numbers: %d\n", total_sum);

    return 0;
}
