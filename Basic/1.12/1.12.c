#include <stdio.h>

int main() {
    int planCode;
    float dataUsage_GB;
    

    printf("Enter Your Plan Code (1.Basic, 2.Premium): ");
    scanf("%d", &planCode);

    printf("Enter Data Usage in GB: ");
    scanf("%f", &dataUsage_GB);

   
    if(planCode == 1) {  

        float totalbill = 299.0;
        if(dataUsage_GB > 10.0) {
            totalbill += 10*(dataUsage_GB - 10.0);
        }

        printf("Total Bill: %.2f\n", totalbill);


    }

    else if (planCode == 2) {          

        float totalbill = 599.0;
        if(dataUsage_GB > 15.0) {

            totalbill += 50 + 5*(dataUsage_GB - 20.0);
        }

        printf("Total Bill: %.2f\n", totalbill);


    }
   
    else {

        printf("Invalid Plan Code\n");
        
        return 0;

    }

    
}
