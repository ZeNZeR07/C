#include <stdio.h>

#define ROWS 3
#define COLS 3

int main(void) {
    int data[ROWS][COLS];
    int i;
    int j;
    
   for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            scanf("%d", &data[i][j]);
        }
    }

    printf("\n--- TWO-DIMENSIONAL ARRAY REPORT ---\n");
    printf("Array Size: %d Rows x %d Columns\n", ROWS, COLS);
    printf("Content (Table Format):\n");

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }

    return 0;
}
