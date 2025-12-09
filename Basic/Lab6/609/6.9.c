#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MONTHS 3

int analyze_profitability(int *rev_ptr, int *exp_ptr, int size, int *status_ptr);
void get_monthly_data(int array[], int size, const char *type);
void print_monthly_data(int array[], int size, const char *type);

int main() {
    int monthly_revenue[MONTHS];
    int monthly_expense[MONTHS];
    int net_profit;
    int business_status;

    get_monthly_data(monthly_revenue, MONTHS, "REVENUE");
    get_monthly_data(monthly_expense, MONTHS, "EXPENSE");
    
    net_profit = analyze_profitability(monthly_revenue, monthly_expense, MONTHS, &business_status);

    printf("\n--- 3 MONTH FINANCIAL ANALYSIS REPORT ---\n");
    
    print_monthly_data(monthly_revenue, MONTHS, "REVENUE");
    print_monthly_data(monthly_expense, MONTHS, "EXPENSE");

    printf("NET PROFIT: %d\n", net_profit);
    
    if (business_status == 1) {
        printf("BUSINESS STATUS: PROJECT IS PROFITABLE\n");
    } else {
        printf("BUSINESS STATUS: PROJECT IS UNPROFITABLE\n");
    }

    return 0;
}

int analyze_profitability(int *rev_ptr, int *exp_ptr, int size, int *status_ptr) {
    long total_revenue = 0;
    long total_expense = 0;
    int net_profit = 0;
    
    for (int month_index = 0; month_index < size; month_index++) {
        total_revenue += *(rev_ptr + month_index);
        total_expense += *(exp_ptr + month_index);
    }
    
    net_profit = (int)(total_revenue - total_expense);
    
    if (net_profit > 0) {
        *status_ptr = 1;
    } else {
        *status_ptr = 0;
    }
    
    return net_profit;
}

void get_monthly_data(int array[], int size, const char *type) {
    printf("\nEnter %d months of %s values:\n", size, type);
    for (int month_index = 0; month_index < size; month_index++) {
        printf("Month %d %s: ", month_index + 1, type);
        if (scanf("%d", &array[month_index]) != 1) {
            printf("Invalid input. Setting value to 0.\n");
            array[month_index] = 0;
            while(getchar() != '\n'); 
        }
    }
}

void print_monthly_data(int array[], int size, const char *type) {
    long total = 0;
    for (int month_index = 0; month_index < size; month_index++) {
        total += array[month_index];
    }
    
    printf("TOTAL %s: %ld\n", type, total); 
}