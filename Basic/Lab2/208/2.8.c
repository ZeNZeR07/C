#include <stdio.h>

int main(){
    int N, i;
    int studenId, score, totalClasses, absentClasses;
    float attendancePercentage;
    int passCount = 0;
    int failCount = 0;
    
    printf("Enter Number of Students: ");
    scanf("%d", &N);
    for ( i = 0; i < N; i++ ){
        
        printf("Enter Student ID: ");
        scanf("%d", &studenId);

        printf("Enter Score: ");
        scanf("%d", &score);

        printf("Enter Total Classes: ");
        scanf("%d", &totalClasses);

        printf("Enter Absent Classes: ");
        scanf("%d", &absentClasses);

        attendancePercentage = ((totalClasses - absentClasses) / totalClasses * 100);

        if(score >= 50 && attendancePercentage >= 75){

            passCount++;
            printf("Student %d: PASS\n", studenId);

        }
        else {

            failCount++;
       
            
            if(score < 50){

                printf("Student %d: FAIL - Low Score\n", studenId);

            }
            else if(attendancePercentage < 75){

                printf("Student %d: FAIL - Low Attendance(70.00%)\n", studenId);
            }

        }
        
    }

    printf("---Summary---\n");
    printf("Total Pass: %d\n", passCount);
    printf("Total Fail: %d\n", failCount);

    return 0;


}