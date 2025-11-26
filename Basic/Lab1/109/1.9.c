#include <stdio.h>

int main() {
    int zoneCode ;
    float weight_kg ;
    float totalCost = 0.0 ;


    printf("Enter Zone Code (1=Local, 2=Regional, 3=International): ");
    scanf("%d", &zoneCode);

    printf("Enter Weight (kg): ");
    scanf("%f", &weight_kg);

    switch (zoneCode) {

        case 1: 

            if (weight_kg <= 5.0) {

                totalCost = 50.0;

            } else {

                totalCost = 80.0;
            }
            break;


        case 2: 

            if (weight_kg <= 10.0) {
                totalCost = 150.0;

            } else {
                
                totalCost = 250.0;
            }
            break;

        case 3: 

            totalCost = 500.0;
            break;

        default:

            printf("Invalid Zone Code\n");
            return 0;


    }


    printf("Total Cost: %.2f Baht\n", totalCost);

    return 0 ;


}
