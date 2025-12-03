#include <stdio.h>

int calculate_change_amount(int cost, int paid);
int count_denomination(int *change_remaining, int denomination);

int main(void) {
    int total_cost;
    int amount_paid;
    int change_amount;
    int remaining_change;

    int count_1000;
    int count_500;
    int count_100;
    int count_50;
    int count_20;
    int count_10;
    int count_5;
    int count_2;
    int count_1;

    printf("Enter Total Cost (integer): ");
    if (scanf("%d", &total_cost) != 1) {
        return 1;
    }

    printf("Enter Amount Paid (integer): ");
    if (scanf("%d", &amount_paid) != 1) {
        return 1;
    }

    change_amount = calculate_change_amount(total_cost, amount_paid);

    printf("\n--- CHANGE CALCULATION REPORT ---\n");
    printf("Total Cost: %d\n", total_cost);
    printf("Amount Paid: %d\n", amount_paid);
    printf("Change Amount: %d\n", change_amount);

    if (change_amount == -1) {
        printf("\nERROR: Amount Paid is less than Total Cost.\n");
        return 1;
    }

    printf("\nDenomination Breakdown:\n");

    if (change_amount > 0) {
        remaining_change = change_amount;

        count_1000 = count_denomination(&remaining_change, 1000);
        count_500  = count_denomination(&remaining_change, 500);
        count_100  = count_denomination(&remaining_change, 100);
        count_50   = count_denomination(&remaining_change, 50);
        count_20   = count_denomination(&remaining_change, 20);
        count_10   = count_denomination(&remaining_change, 10);
        count_5    = count_denomination(&remaining_change, 5);
        count_2    = count_denomination(&remaining_change, 2);
        count_1    = count_denomination(&remaining_change, 1);

        if (count_1000 > 0) {
            printf("1000 Baht: %d\n", count_1000);
        }
        if (count_500 > 0) {
            printf("500 Baht: %d\n", count_500);
        }
        if (count_100 > 0) {
            printf("100 Baht: %d\n", count_100);
        }
        if (count_50 > 0) {
            printf("50 Baht: %d\n", count_50);
        }
        if (count_20 > 0) {
            printf("20 Baht: %d\n", count_20);
        }
        if (count_10 > 0) {
            printf("10 Baht: %d\n", count_10);
        }
        if (count_5 > 0) {
            printf("5 Baht: %d\n", count_5);
        }
        if (count_2 > 0) {
            printf("2 Baht: %d\n", count_2);
        }
        if (count_1 > 0) {
            printf("1 Baht: %d\n", count_1);
        }
    }

    return 0;
}

int calculate_change_amount(int cost, int paid) {
    if (paid >= cost) {
        return paid - cost;
    } else {
        return -1;
    }
}

int count_denomination(int *change_remaining, int denomination) {
    int count;

    count = *change_remaining / denomination;
    *change_remaining = *change_remaining % denomination;

    return count;
}
