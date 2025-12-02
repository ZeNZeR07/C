#include <stdio.h>

struct Employee {
    int id;
    int gross_salary;
    int bonus;
    int total_income;
};


int calculate_net_salary(int total_income) {
    int tax;

    if (total_income > 30000) {

        tax = total_income * 10 / 100;

    } else {

        tax = total_income * 5 / 100;

    }

    return total_income - tax;


}


int main(void) {
    struct Employee emp;
    int net_salary;


    printf("Enter Employee ID: ");

    if (scanf("%d", &emp.id) != 1) {
        return 1;

    }

    printf("Enter Gross Salary: ");

    if (scanf("%d", &emp.gross_salary) != 1) {
        return 1;
        
    }

    printf("Enter Bonus: ");

    if (scanf("%d", &emp.bonus) != 1) {

        return 1;

    }

    
    emp.total_income = emp.gross_salary + emp.bonus;
    net_salary = calculate_net_salary(emp.total_income);


    printf("\n--- EMPLOYEE SALARY REPORT ---\n");
    printf("Employee ID: %d\n", emp.id);
    printf("Gross Salary: %d\n", emp.gross_salary);
    printf("Bonus: %d\n", emp.bonus);
    printf("Total Income: %d\n", emp.total_income);
    printf("Net Salary: %d\n", net_salary);

    return 0;


}

