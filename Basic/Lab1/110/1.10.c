#include <stdio.h>

int main() {
    int clearanceLevel, age, isActive;

    printf("Enter your Clearance Level : ");
    scanf("%d", &clearanceLevel);

    printf("Enter your Age : ");
    scanf("%d", &age);

    printf("Enter your Active (1=Yes, 0=No) : ");
    scanf("%d", &isActive);

    if (clearanceLevel == 3 && isActive == 1) {
        printf("Access Granted\n");
    }
    else if (clearanceLevel == 2 && age >= 25 && isActive == 1) {
        printf("Access Granted\n");
    }
    else {
        printf("Access Denied\n");
    }


    return 0;


}
