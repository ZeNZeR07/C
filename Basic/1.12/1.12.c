#include <stdio.h>

int main() {
    int planCode;
    float dataUsage_GB;
    float totalBill = 0.0;

    printf("Enter Your Plan Code (1 = Basic, 2 = Premium): ");
    scanf("%d", &planCode);

    printf("Enter Data Usage in GB: ");
    scanf("%f", &dataUsage_GB);


    if (planCode == 1) {       
            
        totalBill = 299.0;

        if (dataUsage_GB > 10.0) {
            totalBill += 10.0 * (dataUsage_GB - 10.0);
        }
    }
    else if (planCode == 2) {    

        totalBill = 599.0;

        if (dataUsage_GB > 20.0) {
            totalBill += 50.0 + 5.0 * (dataUsage_GB - 20.0);
        }
    }
    else {
        printf("Invalid Plan Code\n");
        return 0;
    }


    printf("Total Bill: %.2f\n", totalBill);

    return 0;

}
