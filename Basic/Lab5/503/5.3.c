#include <stdio.h>

#define SIZE 5

int calculate_sum(int arr[], int size){

}

int main(){
    int numbers[SIZE];
    int total_sum;
    float average;
    int i;


    printf("Enter %d interger numbers:\n", SIZE);
    for(i = 0; i < SIZE; i++){
        if(scanf("%d", &numbers[i]) != 1){
            return 1;
        }
    }


    average = (float)total_sum / SIZE;

    printf("\n--- ARRAY STATISTICS REPORT ---\n");

}