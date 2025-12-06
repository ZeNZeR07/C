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

    for (index = 0; index < count; index++) {
        printf("Enter data[%d] : ", index);
        scanStatus = scanf("%d", &arr[index]);
        if (scanStatus != 1) {
            count = index;
            break;
        }
    }

    *numPtr = count;
    return arr;
}

int main() {
    int *data;
    int num;
    int i;

    data = GetSet(&num);

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
