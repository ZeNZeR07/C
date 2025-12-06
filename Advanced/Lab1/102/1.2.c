#include <stdio.h>
#include <stdlib.h>


void GetSet(int **data, int *num) {

    printf("Enter number of members: ");
    scanf("%d", num);


    *data = (int *)malloc(*num * sizeof(int));


    for (int i = 0; i < *num; i++) {
        printf("Enter data[%d] : ", i);
        scanf("%d", &((*data)[i]));
    }
}

int main() {
    int *data, num;

    GetSet(&data, &num);


    printf("\n--- Result ---\n");
    for (int i = 0; i < num; i++) {
        printf("data[%d] = %d\n", i, data[i]);
    }


    free(data);

    return 0;5
}
