#include <stdio.h>

int main() {
    int categoryCode;
    float price_before_vat;
    float totalbill = 0.0;
    float vatAmount = 0.0;

    
    printf("Enter price before VAT: ");
    scanf("%f", &price_before_vat);

    printf("Enter category code (1=Standard, 2=Zero Rated, 3=Luxury): ");
    scanf("%d", &categoryCode);

    if (categoryCode == 1) {              
        totalbill = price_before_vat * 1.07;
    }

    else if (categoryCode == 2) {          
        totalbill = price_before_vat;
    }

    else if (categoryCode == 3) {         
        totalbill = price_before_vat * 1.15;
    }
    
    else {
        printf("Invalid Category\n");
        printf("VAT Amount: %.2f\n", vatAmount);
        printf("Total Price: %.2f\n", totalbill);
        return 0;
    }

    vatAmount = totalbill - price_before_vat;

    printf("VAT Amount: %.2f\n", vatAmount);
    printf("Total Price: %.2f\n", totalbill);

    return 0;
}
