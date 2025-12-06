#include <stdio.h>
#include <stdlib.h>

int *GetSet(int *numPtr) {
    int count;
    int scanStatus;
    int index;
    int *arr;

    *numPtr = 0;

    printf("Enter number of members: ");
    scanStatus = scanf("%d", &count);

    if (scanStatus != 1 || count <= 0) {
        return NULL;
    }

    arr = (int *)malloc(count * sizeof(int));1
    if (arr == NULL) {
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

int IsValidSet(int *data, int count) {
    if (data == NULL) {
        return 0;
    }
    if (count <= 0) {
        return 0;
    }
    return 1;
}

void PrintSet(int *data, int count) {
    int i;
    i = 0;
    while (i < count) {
        printf("data[%d] = %d\n", i, data[i]);
        i = i + 1;
    }
}

void FreeSet(int **dataPtr) {
    if (*dataPtr != NULL) {
        free(*dataPtr);
        *dataPtr = NULL;
    }
}

int main(void) {
    int *data;
    int num;

    data = NULL;
    num = 0;

    data = GetSet(&num);

    if (!IsValidSet(data, num)) {
        printf("No valid data.\n");
        FreeSet(&data);
        return 1;
    }

    printf("\n--- Result ---\n");
    PrintSet(data, num);

    FreeSet(&data);

    return 0;
}
