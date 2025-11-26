#include <stdio.h>

int main() {

    int N_MONTHS, month, successCount = 0;
    float dailyDeposit, monthlyTotal;

    printf("Enter Number of Months: ");
    scanf("%d", &N_MONTHS);

    for (month = 1; month <= N_MONTHS; month++) {

        monthlyTotal = 0.0f;

        while (1) {
            printf("Enter Daily Deposit for Month %d: ", month);
            if (scanf("%f", &dailyDeposit) != 1) {
                return 1;   
            }

            if (dailyDeposit == 0.0f) {
                break;      
            }

            monthlyTotal += dailyDeposit;
        }

       
        printf("Month %d Total: %.2f\n", month, monthlyTotal);

        if (monthlyTotal >= 500.0f) {
            successCount++;
        }
    }

    printf("Success Count: %d\n", successCount);

    return 0;
    

}
