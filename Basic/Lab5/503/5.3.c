#include <stdio.h>

#define SIZE 5

int calculate_sum(int arr[], int size) {

    int i;
    int sum = 0;

    for (i = 0; i < size; i++) {
        sum += arr[i];
    }

    return sum;


}

int main(void) {

    int numbers[SIZE];
    int total_sum;
    float average;
    int i;

   

    for (i = 0; i < SIZE; i++) {

        printf("Enter %d integer numbers: ", SIZE);

        if (scanf("%d", &numbers[i]) != 1) {
            return 1;

        }

    }

    total_sum = calculate_sum(numbers, SIZE);
    average = (float)total_sum / SIZE;

    printf("\n--- ARRAY STATISTICS REPORT ---\n");
    printf("Recorded Numbers: ");

    for (i = 0; i < SIZE; i++) {

        printf("%d ", numbers[i]);

        
    }

    printf("\n");
    printf("Total Sum: %d\n", total_sum);
    printf("Average: %.2f\n", average);

    return 0;
}
