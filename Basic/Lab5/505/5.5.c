#include <stdio.h>

#define NUM_STUDENTS 4

struct Student {
    int id;
};

const char* check_id_existence(struct Student students[], int size, int search_id) {
    int i;

    for (i = 0; i < size; i++) {
        if (students[i].id == search_id) {
            return "ID FOUND in the system.";
        }
    }

    return "ID NOT FOUND in the system.";
}

int main(void) {
    struct Student id_list[NUM_STUDENTS];
    int search_id;
    int i;

    printf("Enter IDs for %d students \n", NUM_STUDENTS);

    for (i = 0; i < NUM_STUDENTS; i++) {
        printf("Student %d ID: ", i + 1);
        scanf("%d", &id_list[i].id);
    }

    printf("\nEnter ID to search: ");
    scanf("%d", &search_id);

    const char* result = check_id_existence(id_list, NUM_STUDENTS, search_id);

    printf("\n--- ID SEARCH REPORT ---\n");
    printf("Recorded IDs: ");

    for (i = 0; i < NUM_STUDENTS; i++) {
        printf("%d ", id_list[i].id);
    }

    printf("\n");
    printf("Search ID: %d\n", search_id);
    printf("%s\n", result);

    return 0;
}
