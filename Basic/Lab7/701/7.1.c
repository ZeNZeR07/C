#include <stdio.h>

#define FILENAME "output_data.txt"

int main() {
    FILE *fptr;
    int year = 2025;

    fptr = fopen(FILENAME, "w");
    if (fptr == NULL) {
        printf("ERROR: Could not open file %s for writing.\n", FILENAME);
        return 1;
    }

    fprintf(fptr, "Hello, C File Handling is easy.\n");
    fprintf(fptr, "%d\n", year);

    fclose(fptr);

    printf("--- FILE WRITING PROCESS ---\n");
    printf("Writing data to %s...\n", FILENAME);
    printf("File writing complete.\n");

    printf("\n--- FILE OPERATION REPORT ---\n");
    printf("Action: File created and data written successfully.\n");
    printf("Filename: %s\n", FILENAME);

    return 0;
}
