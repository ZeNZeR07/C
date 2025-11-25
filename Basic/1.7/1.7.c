#include <stdio.h>

int main() {
    int customerType;
    float consumption_kWh;
    float totalBill = 0.0;


    if (scanf("%d %f", &customerType, &consumption_kWh) != 2) {
        return 1;
    }


    if (customerType == 1) {  

        if (consumption_kWh <= 100) {
            totalBill = consumption_kWh * 3.0;
        } else {
            totalBill = consumption_kWh * 4.0;
        }
    }
    
    else if (customerType == 2) { 

        if (consumption_kWh <= 500) {
            totalBill = consumption_kWh * 5.0;
        } else {
            totalBill = consumption_kWh * 6.5;
        }
    }

    else {  
        printf("Invalid Customer Type\n");
        return 0;
    }

    printf("%.2f\n", totalBill);

    return 0;


}
