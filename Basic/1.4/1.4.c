#include <stdio.h>

int main(){
    int N, sum = 0;

    printf("Enter your number:");
    scanf("%d", &N);

    for(int i = 1; i <= N; i++){
        sum += i;

        
    }


    printf("%d\n", sum);
    return 0;


}