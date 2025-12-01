#include <stdio.h>

struct Student {
    char  name[50];    
    int   studentId;   
    float score;      
};

int main() {
    int N;             
    int i;
    int passCount = 0; 
    int failCount = 0; 

   
    if (scanf("%d", &N) != 1 || N <= 0) {
        return 1;  
    }

    struct Student students[N];  

  
    for (i = 0; i < N; i++) {
        if (scanf("%d %f %s",
                  &students[i].studentId,
                  &students[i].score,
                  students[i].name) != 3) {
            return 1; 
        }
    }

  
    for (i = 0; i < N; i++) {
        if (students[i].score >= 60.0) {
            passCount++;
        } else {
            failCount++;
        }
    }


    printf("Pass Count: %d\n", passCount);
    printf("Fail Count: %d\n", failCount);

    return 0;
}
