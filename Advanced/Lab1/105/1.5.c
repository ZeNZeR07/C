#include <stdio.h>
#include <stdlib.h>

void GetMatrix(int **value, int *row, int *col) {
    int r, c;
    int scanStatus;
    int i;

    printf("Enter rows and cols: ");
    scanStatus = scanf("%d %d", &r, &c);

    if (scanStatus != 2 || r <= 0 || c <= 0) {
        *value = NULL;
        *row = 0;
        *col = 0;
        return;
    }

    *value = (int *)malloc(r * c * sizeof(int));
    if (*value == NULL) {
        *row = 0;
        *col = 0;
        return;
    }

    for (i = 0; i < r * c; i++) {
        printf("value[%d] = ", i);
        scanf("%d", &((*value)[i]));
    }

    *row = r;
    *col = c;
}

int main() {
    int *data;
    int m, n;
    int i, j;

    GetMatrix(&data, &m, &n);

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
