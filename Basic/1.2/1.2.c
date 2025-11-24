#include <stdio.h>

int main(){
    int score;
    char *message;

    printf("Enter your Score: ");
    scanf("%d", &score);

    if(score >= 80){
        message = "Grade A";

    }else if(score >= 70){
        message = "Grade B";

    }else if(score >= 60){
        message = "Grade C";

    }else if(score >= 50){
        message = "Grade D";

    }else if(score >= 0){
        message = "Grade F";

    }else{
        message = "Grade is incorrect";
    }

    printf("%s\n", message);
    
}
