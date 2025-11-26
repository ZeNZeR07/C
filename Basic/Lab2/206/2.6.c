#include <stdio.h>

int main() {
    int N_MONTHS, month, successCount = 0;
    float dailyDeposit, monthlyTotal;
    float monthTotals[100];

    printf("Enter Number of Months: ");
    scanf("%d", &N_MONTHS);

    for (month = 1; month <= N_MONTHS; month++) {
        monthlyTotal = 0.0f;


        while (1) {
            printf("Enter Daily Deposit for Month %d: ", month);
            scanf("%f", &dailyDeposit);

            if (dailyDeposit == 0.0f)
                break;

            monthlyTotal += dailyDeposit;
        }

        monthTotals[month - 1] = monthlyTotal;

        if (monthlyTotal >= 500.0f)
            successCount++;
    }



    for (month = 1; month <= N_MONTHS; month++) {
        printf("Month %d Total: %.2f\n", month, monthTotals[month - 1]);
    }
    printf("Success Count: %d\n", successCount);

    return 0;

    
}
