#include <stdio.h>

int main(){
    int score;

    scanf("%d", &score);

    if(score >= 80 && score <= 100){
        printf("Grade A");
    }
    else if(score >= 70){
        printf("Grade B");
    }
    else if(score >= 60){
        printf("Grade C");
    }
    else if(score >= 50){
        printf("Grade D");
    }
    else if(score >= 0){
        printf("Grade F");
    }
    else{
        printf("Grade is incorrect");
    }

    return 0;
}
