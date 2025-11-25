#include <stdio.h>

int main() {

    int termCode;
    float investmentAmount;
    float aprRate = 0.0;
    float totalInterest = 0.0;

    printf("Enter Term Code (1, 2, 3): ");
    scanf("%d", &termCode);

    printf("Enter Investment Amount: ");
    scanf("%f", &investmentAmount);

    switch (termCode) {

        case 1:
            if (investmentAmount < 5000) {
                aprRate = 3.0;
            } else {
                aprRate = 4.0;
            }
            break;

        case 2:
            if (investmentAmount < 10000) {
                aprRate = 5.0;
            } else {
                aprRate = 6.5;
            }
            break;

        case 3:
            aprRate = 8.0;
            break;

        default:
            printf("Invalid Term Code\n");
            return 0;
    }

    totalInterest = investmentAmount * aprRate / 100;
    printf("Total Interest: %.2f\n", totalInterest);

    return 0;
}
