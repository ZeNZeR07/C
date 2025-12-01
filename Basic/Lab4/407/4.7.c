#include <stdio.h>

#define MAX_SIZE 10

int main() {
    int data[MAX_SIZE];
    int N;
    int search_value;
    int count = 0;
    int i;

   
    printf("Enter the number of elements (N, max %d): ", MAX_SIZE);
    scanf("%d", &N);

    if (N > MAX_SIZE || N < 1) {
        N = MAX_SIZE;
    }


    printf("Enter %d integer numbers:\n", N);
    for (i = 0; i < N; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &data[i]);
    }


    printf("Enter the search value: ");
    scanf("%d", &search_value);


    for (i = 0; i < N; i++) {
        if (data[i] == search_value) {
            count++;
        }
    }


    printf("\n--- FREQUENCY ANALYSIS REPORT ---\n");
    printf("Total elements recorded (N): %d\n", N);

    printf("Recorded Numbers: ");
    for (i = 0; i < N; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    printf("Search Value: %d\n", search_value);
    printf("Frequency Count: %d\n", count);

    return 0;
}
