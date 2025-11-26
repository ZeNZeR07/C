#include <stdio.h>

struct Product{
    char name[50];
    int productId;
    float price;
};

int main() {

    struct Product item;

    if(scanf("%d %f %s", &item.productId, &item.price, item.name) !=3){
        return 1;
    }

    printf("ID: %d, ", item.productId);
    printf("Price: %.2f, ", item.price);
    printf("Name: %s ", item.name);

    return 0;

    

}