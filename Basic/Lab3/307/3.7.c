#include <stdio.h>

struct SalesRecord {
    char  name[50];
    float target;
    float actual;
};

int main(void) {
    int   numRecords = 0;
    int   i;
    float grandTotalCommission = 0.0f;

    if (scanf("%d", &numRecords) != 1 || numRecords <= 0) {
        printf("Invalid number of records.\n");
        return 1;
    }

    struct SalesRecord records[numRecords];

    for (i = 0; i < numRecords; i++) {
        float baseCommission = 0.0f;

        if (scanf("%f %f %49s",
                  &records[i].target,
                  &records[i].actual,
                  records[i].name) != 3) {
            printf("Invalid input data.\n");
            return 1;
        }

        if (records[i].target <= 0.0f ||
            records[i].actual < 0.0f   ||
            records[i].name[0] == '\0') {
            printf("Invalid target/actual/name for %s. Skipping.\n",
                   records[i].name);
            continue;
        }

        baseCommission = records[i].actual * 0.10f;

        if (records[i].actual > records[i].target * 1.20f) {
            baseCommission += 200.0f;
        } else if (records[i].actual >= records[i].target) {
            baseCommission += 50.0f;
        } else if (records[i].actual < records[i].target * 0.90f) {
            baseCommission -= 100.0f;
        }

        grandTotalCommission += baseCommission;
    }

    printf("Grand Total Commission: %.2f\n", grandTotalCommission);

    return 0;
}
