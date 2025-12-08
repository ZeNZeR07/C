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

    index = 0;
    while (index < *memberCountPtr) {
        printf("Enter data[%d] : ", index);
        scanStatus = scanf("%d", &((*setDataPtr)[index]));

        if (scanStatus != 1) {
            *memberCountPtr = index;
            break;
        }

        index = index + 1;
    }
}

int main(void) {
    int *setData;
    int memberCount;
    int index;

    setData = NULL;
    memberCount = 0;

    GetSet(&setData, &memberCount);

    if (setData == NULL || memberCount <= 0) {
        printf("No valid data. Program will exit.\n");
        return 1;
    }

    printf("\n--- Result ---\n");

    index = 0;
    while (index < memberCount) {
        printf("data[%d] = %d\n", index, setData[index]);
        index = index + 1;
    }

    free(setData);
    setData = NULL;

    return 0;

    
}
