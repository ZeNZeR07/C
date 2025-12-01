#include <stdio.h>

#define MAX_SIZE 10
int main(){
    int data[MAX_SIZE];
    int status[MAX_SIZE] ; 
    int N;
    int i, j;
    int count;
    const int UNVISITED = 0;
    const int VISITED = 1;



    for (i = 0; i < MAX_SIZE; i++) {
        status[i] = UNVISITED;

    }
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


    printf("\n--- UNIQUE ELEMENTS REPORT ---\n");
    printf("Total elements recorded (N): %d\n", N);
    printf("Recorded Numbers: ");
    for (i = 0; i < N; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    printf("Number   |  Frequency\n");
    printf("-------------------\n");
    for (i = 0; i < N; i++) {
        if (status[i] == UNVISITED) {
            count = 1;
            for (j = i + 1; j < N; j++) {
                if (data[i] == data[j]) {
                    count++;
                    status[j] = VISITED;
                }
            }
            printf("   %d     |    %d\n", data[i], count);
        }
    }
    return 0;   
}