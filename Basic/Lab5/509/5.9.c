#include <stdio.h>

struct Product {
    char item_id[20];
    float cost_price;
    float sell_price;
    int stock_quantity;
};

float calculate_total_profit(float cost, float sell, int qty);
float calculate_profit_percentage(float cost, float sell);

int main(void) {
    struct Product item;
    float total_profit;
    float profit_percent;

    printf("Enter Item ID : ");
    scanf("%s", item.item_id);

    printf("Enter Cost Price per unit: ");
    scanf("%f", &item.cost_price);

    printf("Enter Sell Price per unit: ");
    scanf("%f", &item.sell_price);

    printf("Enter Stock Quantity: ");
    scanf("%d", &item.stock_quantity);

    total_profit = calculate_total_profit(item.cost_price, item.sell_price, item.stock_quantity);
    profit_percent = calculate_profit_percentage(item.cost_price, item.sell_price);

    printf("\n--- INVENTORY PROFIT REPORT ---\n");
    printf("Item ID: %s\n", item.item_id);
    printf("Cost Price: %.2f, Sell Price: %.2f, Stock: %d\n",
           item.cost_price, item.sell_price, item.stock_quantity);
    printf("Total Profit: %.2f\n", total_profit);
    printf("Profit Percentage: %.2f%%\n", profit_percent);

    if (total_profit > 0) {
        printf("Status: Profit\n");
    } else if (total_profit < 0) {
        printf("Status: Loss\n");
    } else {
        printf("Status: Break Even\n");
    }

    return 0;
}

float calculate_total_profit(float cost, float sell, int qty) {
    return (sell - cost) * qty;
}

float calculate_profit_percentage(float cost, float sell) {
    return ((sell - cost) / cost) * 100.0f;
}
