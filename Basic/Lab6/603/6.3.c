#include <stdio.h>

#define SIZE 3

int main(void) {
    int data[SIZE];
    int *ptr;
    int i;

    printf("Enter %d integer elements for the array:\n", SIZE);
    for (i = 0; i < SIZE; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &data[i]);
    }

    ptr = data;

    printf("\n--- ARRAY AND POINTER REPORT ---\n");
    printf("Index | Value (Direct) | Value (via Pointer) | Address\n");
    printf("------------------------------------------------------\n");

    for (i = 0; i < SIZE; i++) {
        printf("%5d | %14d | %18d | %p\n",
               i,
               data[i],
               *(ptr + i),
               (ptr + i));
    }

    return 0;
}
