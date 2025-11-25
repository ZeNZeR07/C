#include <stdio.h>

int main() {
    int clearanceLevel, age , isActive;


    printf("Enter your ClearanceLevel : ");
    scanf("%d", &clearanceLevel);

    printf("Enter your age : ");
    scanf("%d", &age);
    
    printf("Enter your Active : ");
    scanf("%d", &isActive);

    if(clearanceLevel == 3 && isActive == 1 ){

        printf("Access Granted\n");

    }
    else if(clearanceLevel == 2 && age >=25 && isActive == 1){

        printf("Access Granted");

    }
    else{

        printf("Access Denied");

    }


}