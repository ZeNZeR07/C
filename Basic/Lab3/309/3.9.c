#include <stdio.h>

int main(void) {

    int   N_DAYS;
    int   day;
    float initialBudget;
    float remainingBudget;
    float dailySpend;

    if (scanf("%f %d", &initialBudget, &N_DAYS) != 2) {
        return 1;
    }

    if (initialBudget < 0.0f || N_DAYS <= 0) {
        return 1;
    }

    remainingBudget = initialBudget;

    printf("Day | Spend | Remaining\n");
    printf("-----------------------\n");

    for (day = 1; day <= N_DAYS; day++) {
        dailySpend = 0.0f;

        if (remainingBudget >= 500.00f) {
            dailySpend = 100.00f;
        } else if (remainingBudget >= 100.00f) {
            dailySpend = 50.00f;
        } else if (remainingBudget > 0.0f) {
            dailySpend = 20.00f;
        } else {
            dailySpend = 0.0f;
        }

        if (dailySpend > remainingBudget) {
            dailySpend = remainingBudget;
        }

        remainingBudget -= dailySpend;

        printf("%d | %.2f | %.2f\n", day, dailySpend, remainingBudget);
    }

    printf("-----------------------\n");
    printf("Final Budget: %.2f\n", remainingBudget);

    return 0;
}
