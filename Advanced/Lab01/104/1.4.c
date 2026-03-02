#include <stdio.h>
#include <stdlib.h>

int GetSet(int **dataPtr) {
    int count;
    int i;

    printf("Enter number of members: ");
    if (scanf("%d", &count) != 1 || count <= 0) {
        *dataPtr = NULL;
        return 0;
    }

    *dataPtr = (int *)malloc(count * sizeof(int));
    if (*dataPtr == NULL) {
        return 0;
    }

    for (i = 0; i < count; i++) {
        printf("Enter data[%d] : ", i);
        scanf("%d", &((*dataPtr)[i]));
    }

    return count;
}

int main() {
    int *data;
    int num;
    int i;

    num = GetSet(&data);

    if (data == NULL || num <= 0) {
        printf("No valid data.\n");
        return 1;
    }

    printf("\n--- Result ---\n");
    for (i = 0; i < num; i++) {
        printf("data[%d] = %d\n", i, data[i]);
    }

    free(data);
    return 0;
}
