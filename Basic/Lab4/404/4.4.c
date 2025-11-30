#include <stdio.h>

#define SIZE 5

int main() {
    int number[SIZE];
    int even_count = 0;
    int odd_count = 0;
    int i;


    for (i = 0; i < SIZE; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &number[i]);
        if (number[i] % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }

    printf("\n--- Number CLASSIFICATION ---\n");
    printf("Recorded Numbers: ");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", number[i]);
    
    }
    printf("\n");
    printf("Total Even Numbers: %d\n", even_count);
    printf("Total Odd Numbers: %d\n", odd_count);

    return 0;

}