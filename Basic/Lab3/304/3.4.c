#include <stdio.h>

struct Student{
    char name[50];
    int studentId;
    float score;
};

int main() {
    int N, i;
    int passedCount = 0;
    int failedCount = 0;

    if(scanf("%d", &N) != 1 || N <= 0){
        return 1;
    }
 
    struct Student students[N];
    
    for(i = 0; i < N; i++){

        if(scanf("%d %f %s", &students[i].studentId, &students[i].score, students[i].name) != 3){
            return 1;
        }


    }

    for(i = 0; i < N; i++){
        if(students[i].score >= 60.0){
            passedCount++;
        } else {
            failedCount++;
        }
    }

    printf("Passed: %d\n", passedCount);
    printf("Failed: %d\n", failedCount);
    
    return 0;


}