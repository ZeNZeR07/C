#include <stdio.h>

struct Transaction {
    char description[50];
    float amount;
};



int main() {
    int N, i;
    float totalIncome = 0.0;
    float totalExpense = 0.0;
    float netBalance;

    if(scanf("%d", &N) != 1) {
        return 1;
    }

    struct Transaction transactions[N];


    for(i = 0; i < N; i++) {
        if(scanf("%f %s", &transactions[i].amount, transactions[i].description) != 2) {
            return 1;
        }
        if(transactions[i].amount >= 0.0) {
            totalIncome += transactions[i].amount;
         
        } else {
            totalExpense += -transactions[i].amount;
        }
    }

    netBalance = totalIncome - totalExpense;
    printf("Total Income: %.2f\n", totalIncome);
    printf("Total Expense: %.2f\n", totalExpense);
    printf("Net Balance: %.2f\n", netBalance);

    return 0;
}