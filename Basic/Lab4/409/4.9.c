#include <stdio.h>

int main(void) {
    int gross_salary;
    float tax_rate = 0.0;
    float tax_amount = 0.0;
    float net_salary = 0.0;

    printf("Enter Gross Salary (THB/month, integer): ");

    if (scanf("%d", &gross_salary) != 1) {
        return 1;
    }

    if (gross_salary < 0) {
        gross_salary = 0;
    }

    if (gross_salary < 20000) {
        tax_rate = 0.0;
    } else if (gross_salary <= 30000) {
        tax_rate = 0.05;
    } else if (gross_salary <= 50000) {
        tax_rate = 0.10;
    } else {
        tax_rate = 0.15;
    }

    tax_amount = gross_salary * tax_rate;
    net_salary = (float)gross_salary - tax_amount;

    printf("\n--- SALARY CALCULATION REPORT ---\n");
    printf("Gross Salary: %d THB\n", gross_salary);
    printf("Tax Rate Applied: %.0f%%\n", tax_rate * 100.0);
    printf("Tax Amount Deducted: %.2f THB\n", tax_amount);
    printf("Net Salary: %.2f THB\n", net_salary);

    return 0;
}
