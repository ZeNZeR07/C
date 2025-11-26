#include <stdio.h>

int main() {
    int N, i, quantity;
    float unitPrice, itemCost, grandTotal = 0.0;


    printf("Enter number of items : ");
    scanf("%d", &N);

    for (i = 0; i < N; i++) {


        printf("Enter unit price for item: ");
        scanf("%f", &unitPrice);


        printf("Enter quantity for item: ");
        scanf("%d", &quantity);

        itemCost = unitPrice * quantity;

        if (unitPrice >= 1000.00) {
            itemCost = itemCost * 0.9;   
        }

        grandTotal += itemCost;
        
    }

    printf("Grand Total: %.2f\n ", grandTotal);

    return 0;


}
