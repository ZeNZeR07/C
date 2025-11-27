#include <stdio.h>

#define VAT_RATE 0.07

struct Item {
    char name[50];
    float unitPrice;
    int quantity;
};

int main(void) {
    int N, i;
    float subTotal = 0.0;
    float totalVAT = 0.0;
    float grandTotal = 0.0;

    if (scanf("%d", &N) != 1) {
        return 1;
    }

    struct Item items[N];

    printf("--- RECEIPT ---\n");

    for (i = 0; i < N; i++) {
        float itemCost;

        if (scanf("%s %f %d",
                  items[i].name,
                  &items[i].unitPrice,
                  &items[i].quantity) != 3) {
            return 1;
        }

        itemCost = items[i].unitPrice * items[i].quantity;

        printf("%s x %d = %.2f\n",
               items[i].name,
               items[i].quantity,
               itemCost);

        subTotal += itemCost;
    }

    totalVAT = subTotal * VAT_RATE;
    grandTotal = subTotal + totalVAT;

    printf("--------------\n");
    printf("Subtotal: %.2f\n", subTotal);
    printf("VAT (7%%): %.2f\n", totalVAT);
    printf("Grand Total: %.2f\n", grandTotal);

    return 0;
}
