#include <stdio.h>

#define SIZE 5

void sort_array_ascending(int array[], int size);
void print_array(int array[], int size);

int main(void) {
    int numbers[SIZE];
    int original_copy[SIZE];
    int i;

    printf("Enter %d integer numbers for sorting:\n", SIZE);

    for (i = 0; i < SIZE; i++) {
        printf("Element %d: ", i + 1);
        if (scanf("%d", &numbers[i]) != 1) {
            return 1;
        }
        original_copy[i] = numbers[i];
    }

    printf("\n--- ARRAY SORTING REPORT ---\n\n");

    printf("Original Array: ");
    print_array(original_copy, SIZE);

    sort_array_ascending(numbers, SIZE);

    printf("Sorted Array (Ascending): ");
    print_array(numbers, SIZE);

    return 0;
}

void print_array(int array[], int size) {
    int i;

    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");
}

void sort_array_ascending(int array[], int size) {
    int i;
    int j;
    int temp;

    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            if (array[j] < array[i]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}
