#include <stdio.h>

int main() {
    int initialStock, N, cmdCode, quantity;
    int currentStock;
    float PENALTY_FEE;
    float totalPenalties = 0.0f;

    
    printf("Enter Initial Stock: ");
    if (scanf("%d", &initialStock) != 1) {
        return 1;
    }

    printf("Enter Penalty Fee: ");
    if (scanf("%f", &PENALTY_FEE) != 1) {
        return 1;
    }

    printf("Enter Number of Commands: ");
    if (scanf("%d", &N) != 1) {
        return 1;
    }

    currentStock = initialStock;

   
    for (int i = 0; i < N; i++) {

        printf("Enter Command Code (1=Receive, 2=Ship, 3=Status): ");
        if (scanf("%d", &cmdCode) != 1) {
            return 1;
        }

       
        printf("Enter Quantity: ");
        if (scanf("%d", &quantity) != 1) {
            return 1;
        }

        switch (cmdCode) {

        case 1:
            if (quantity <= 0) {
                printf("Error: Quantity must be positive.\n");
            } else {
                currentStock += quantity;
                printf("Received %d units.\n", quantity);
            }
            break;

        case 2: 
            if (quantity <= 0) {
                printf("Error: Quantity must be positive.\n");
            } else if (quantity <= currentStock) {
                currentStock -= quantity;
                printf("Shipped %d units.\n", quantity);
            } else {
                totalPenalties += PENALTY_FEE;
                printf("FAILURE: Insufficient stock. PENALTY %.2f added.\n",
                       PENALTY_FEE);
            }
            break;

        case 3: 
            printf("Current Stock: %d\n", currentStock);
            printf("Total Penalties: %.2f\n", totalPenalties);
            break;

        default:
            printf("Error: Invalid Command.\n");
            break;
        }
    }

    return 0;
}
