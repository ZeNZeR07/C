#include <stdio.h>

int main() {
    int   N_PERIODS, cmdCode, i;
    float initialBalance, PENALTY_FEE, amount;
    float currentBalance;
    float totalPenalties = 0.0f;
    float APR, interest; 


    if (scanf("%f %f %d", &initialBalance, &PENALTY_FEE, &N_PERIODS) != 3) {
        return 1;
    }

    currentBalance = initialBalance;


    printf("Starting Balance: %.2f\n", currentBalance);


    for (i = 1; i <= N_PERIODS; i++) {


        if (scanf("%d %f", &cmdCode, &amount) != 2) {
            return 1;
        }

        printf("--- Month %d ---\n", i);

        switch (cmdCode) {
        case 1: 
            currentBalance += amount;
            printf("Deposit: %.2f\n", amount);
            break;

        case 2:  
            if (amount <= currentBalance) {
                currentBalance -= amount;
                printf("Withdrawal: %.2f\n", amount);
            } else {
                totalPenalties += PENALTY_FEE;
                printf("WITHDRAWAL FAILED. Penalty %.2f applied.\n",
                       PENALTY_FEE);
            }
            break;

        case 3: 

            if (currentBalance < 1000.0f) {
                APR = 0.01f;   
            } else {
                APR = 0.025f;    
            }


            interest = currentBalance * (APR / 12.0f);
            currentBalance += interest;

            printf("Interest: %.2f (Rate: %.2f%%)\n",
                   interest, APR * 100.0f);
            break;

        default:
            printf("Error: Invalid Command.\n");
            break;
        }
    }


    printf("Final Balance: %.2f\n", currentBalance);
    printf("Total Penalties: %.2f\n", totalPenalties);

    return 0;
}
