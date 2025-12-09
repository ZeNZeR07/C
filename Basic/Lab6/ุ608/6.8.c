#include <stdio.h>

#define SIZE 5

int find_and_update(int *arr_ptr, int size, int search_value, int new_value);
void print_array(int *arr_ptr, int size);

int main(void) {
    int number[SIZE];
    int search_value, new_value, result;
    int i;

    for (i = 0; i < SIZE; i++) {
        scanf("%d", &number[i]);
    }

    scanf("%d", &search_value);
    scanf("%d", &new_value);

    printf("--- ARRAY UPDATE REPORT ---\n");

    printf("Array BEFORE Update: ");
    print_array(number, SIZE);

    result = find_and_update(number, SIZE, search_value, new_value);

    printf("Array AFTER Update: ");
    print_array(number, SIZE);

    printf("Status: ");
    if (result != -1)
        printf("Update SUCCESSFUL.\n");
    else
        printf("Update FAILED.\n");

    return 0;
}

int find_and_update(int *arr_ptr, int size, int search_value, int new_value) {
    for (int i = 0; i < size; i++) {
        if (arr_ptr[i] == search_value) {
            arr_ptr[i] = new_value;
            return i;
        }
    }
    return -1;
}

void print_array(int *arr_ptr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr_ptr[i]);
    }
    printf("\n");
}
