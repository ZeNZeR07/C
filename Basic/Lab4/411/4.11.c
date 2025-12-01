#include <stdio.h>

#define ROWS 2
#define COLS 4

int main(void) {
    int matrix[ROWS][COLS];
    int total_sum = 0;
    int i, j;

    
   for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\n--- 2D MATRIX SUMMATION REPORT ---\n");
    printf("Recorded Matrix (%d Rows x %d Columns):\n", ROWS, COLS);
  

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
            total_sum += matrix[i][j];
        }
        printf("\n");
    }

    printf("Total Sum of Matrix Elements: %d\n", total_sum);

    return 0;
}
