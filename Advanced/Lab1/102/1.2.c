#include <stdio.h>
#include <stdlib.h>

void GetSet(int **setDataPtr, int *memberCountPtr) {
    int scanStatus;
    int index;

    printf("Enter number of members: ");
    scanStatus = scanf("%d", memberCountPtr);

    if (scanStatus != 1 || *memberCountPtr <= 0) {
        *memberCountPtr = 0;
        *setDataPtr = NULL;
        return;
    }

    *setDataPtr = (int *)malloc(*memberCountPtr * sizeof(int));
    if (*setDataPtr == NULL) {
        *memberCountPtr = 0;
        return;
    }

    for (index = 0; index < *memberCountPtr; index++) {
        printf("Enter data[%d] : ", index);
        scanStatus = scanf("%d", &((*setDataPtr)[index]));
        if (scanStatus != 1) {
            *memberCountPtr = index;
            break;
        }
    }
}

int main(void) {
    int *setData = NULL;
    int memberCount = 0;
    int index;

    GetSet(&setData, &memberCount);

    if (setData == NULL || memberCount <= 0) {
        printf("No valid data. Program will exit.\n");
        return 1;
    }

    printf("\n--- Result ---\n");
    for (index = 0; index < memberCount; index++) {
        printf("data[%d] = %d\n", index, setData[index]);
    }

    free(setData);
    setData = NULL;

    return 0;
}
