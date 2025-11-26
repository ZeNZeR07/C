#include <stdio.h>

int main() {
    int initialStock, N, cmdCode, quantity;
    int currentStock;
    float PENALTY_FEE;
    float totalPenalties = 0.0;

    printf("Enter Initial Stock: ");
    scanf("%d", &initialStock);

    printf("Enter Penalty Fee: ");
    scanf("%f", &PENALTY_FEE);

    printf("Enter Number of Commands: ");
    scanf("%d", &N);

    currentStock = initialStock;

    for(int i = 0; i < N; i++) {

        printf("Enter Command Code (1=Receive, 2=Ship, 3=Status): ");
        scanf("%d", &cmdCode);

        printf("Enter Quantity: ");
        scanf("%d", &quantity);

        switch(cmdCode) {

            case 1: 
                currentStock += quantity;
                printf("Received %d units.\n", quantity);
                break;

            case 2:
                if(quantity <= 0) {
                    printf("Error: Quantity must be positive.\n");
                }
                else if(quantity <= currentStock) {
                    currentStock -= quantity;
                    printf("Shipped %d units.\n", quantity);
                }
                else {
                    totalPenalties += PENALTY_FEE;
                    printf("FAILURE: Insufficient stock. PENALTY %.2f added.\n", PENALTY_FEE);
                }
                break;

            case 3:
                printf("Current Stock: %d\n", currentStock);
                printf("Total Penalties: %.2f\n", totalPenalties);
                break;

            default:
                printf("Error: Invalid Command.\n");
        }
    }

    return 0;
}
