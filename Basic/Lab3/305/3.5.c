#include <stdio.h>

#define SHIPPING_FEE 50.0f

struct Order {
    int itemId;
    float unitPrice;
    int quantity;
};

int main() {
    int N, i;
    float grandTotal = 0.0f;

    if (scanf("%d", &N) != 1) {
        return 1;
    }

    struct Order orders[N];

    for (i = 0; i < N; i++) {
        float itemTotal;

        if (scanf("%d %f %d",&orders[i].itemId, &orders[i].unitPrice, &orders[i].quantity) != 3) {
            return 1;
        }

        itemTotal = (orders[i].unitPrice * orders[i].quantity) + SHIPPING_FEE;

        if (itemTotal >= 500.0f) {
            itemTotal *= 0.90f;

        }

        grandTotal += itemTotal;
    }

    printf("Grand Total: %.2f\n", grandTotal);

    return 0;

    
}
