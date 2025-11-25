#include <stdio.h>

int main() {
    float principal, monthlyPayment, interest;
    int month = 0;

    const float INTEREST_RATE = 0.01;
    const float PENALTY = 10.0;

    printf("Principal Amount: ");
    scanf("%f", &principal);

    printf("Monthly Payment Amount: ");
    scanf("%f", &monthlyPayment);


    while (principal > 0 && month < 10) {
        
        interest = principal * INTEREST_RATE;
        principal = principal + interest;

        if (monthlyPayment < interest) {
            principal = principal + PENALTY;
        }

        principal = principal - monthlyPayment;
        month++;

        printf("Month %d: Remaining %.2f\n", month, principal);
    }

    if (principal > 0)

        printf("Loan settled in 10+ months.\n");

    else

        printf("Loan settled in %d months.\n", month);


    return 0;


}
