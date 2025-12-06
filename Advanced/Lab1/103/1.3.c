#include <stdio.h>
#include <stdlib.h>

int *GetSet(int *numPtr) {
    int count;
    int scanStatus;
    int index;
    int *arr;

    printf("Enter number of members: ");
    scanStatus = scanf("%d", &count);

    if (scanStatus != 1 || count <= 0) {
        *numPtr = 0;
        return NULL;
    }

    arr = (int *)malloc(count * sizeof(int));
    if (arr == NULL) {
        *numPtr = 0;
        return NULL;
    }

    index = 0;
    while (index < count) {
        printf("Enter data[%d] : ", index);
        scanStatus = scanf("%d", &arr[index]);

        if (scanStatus != 1) {
            count = index;
            break;
        }

        index = index + 1;
    }

    *numPtr = count;
    return arr;
}

int main(void) {
    int *data;
    int num;
    int i;

    data = NULL;
    num = 0;

    data = GetSet(&num);

    if (data == NULL || num <= 0) {
        printf("No valid data.\n");
        return 1;
    }

    printf("\n--- Result ---\n");

    i = 0;
    while (i < num) {
        printf("data[%d] = %d\n", i, data[i]);
        i = i + 1;
    }

    free(data);
    data = NULL;

    return 0;
}
