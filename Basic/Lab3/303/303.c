#include <stdio.h>

struct Student{
    char name[50];
    int studentId;
    float score;
    
    
}; 

int main() {
    int N, i ;
    float totalScore, AverageScore;

    if(scanf("%d", &N) != 1 || N <= 0){
        return 1;
    }
 
    struct Student students[N];
    
    for(i = 0; i < N; i++){

        if(scanf("%d %f %s", &students[i].studentId, &students[i].score, students[i].name) != 3){
            return 1;
        }
        totalScore += students[i].score;

    }
    AverageScore = totalScore / N;

    printf("Average Score: %.2f", AverageScore);

    return 0;


}