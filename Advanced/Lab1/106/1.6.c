#include <stdio.h>
#include <stdlib.h>

int *GetMatrix(int *row, int *col) {
    int r, c;
    int scanStatus;
    int i;
    int *arr;

    printf("Enter rows and cols: ");
    scanStatus = scanf("%d %d", &r, &c);
    if (scanStatus != 2 || r <= 0 || c <= 0) {
        *row = 0;
        *col = 0;
        return NULL;
    }

    arr = (int *)malloc(r * c * sizeof(int));
    if (arr == NULL) {
        *row = 0;
        *col = 0;
        return NULL;
    }

    for (i = 0; i < r * c; i++) {
        printf("value[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    *row = r;
    *col = c;
    return arr;
}

int main() {
    int *data;
    int m, n;
    int i, j;

    data = GetMatrix(&m, &n);

    if (data == NULL || m <= 0 || n <= 0) {
        printf("No valid matrix.\n");
        return 1;
    }

    printf("\n--- Matrix ---\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", data[i * n + j]);
        }
        printf("\n");
    }

    free(data);
    return 0;
}
