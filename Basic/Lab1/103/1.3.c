#include <stdio.h>

int main(){
    int  num1, num2, operationCode, result;

    
  
    printf("Enter num1 :");
    scanf("%d", &num1);

    printf("Enter num2 :");
    scanf("%d", &num2);

    printf("Enter operation code (1:+ 2:- 3:* 4:/): ");
    scanf("%d", &operationCode);

       switch (operationCode) {
        case 1: 

            result = num1 + num2;
            printf("Result = %d\n", result);
            break;

        case 2: 

            result = num1 - num2;
            printf("Result = %d\n", result);
            break;

        case 3: 

            result = num1 * num2;
            printf("Result = %d\n", result);
            break;

        case 4:

            result = num1 / num2; 
            printf("Result = %d\n", result);
            break;

        default:

            printf("Invalid Operation\n");
            break;

    }

    return 0;


}