#include <stdio.h>

struct Product {
    int itemId;
    float unitPrice;
    int quantity;
};

int main() {
    int N, i;
    float grandTotal = 0.0;

    if(scanf("%d", &N) != 1){
        return 1;
    }

    struct Product products[N];

    for(i = 0; i < N; i++){
        if(scanf("%d %f %d", &products[i].itemId, &products[i].unitPrice, &products[i].quantity) != 3){
            return 1;
        }
        
        grandTotal += products[i].unitPrice * products[i].quantity;
    }

}
