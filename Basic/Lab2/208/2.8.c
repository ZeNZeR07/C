#include <stdio.h>

int main() {
    int N, i;
    int studentId, score, totalClasses, absentClasses;
    float attendancePercent;
    int passCount = 0;
    int failCount = 0;

    if (scanf("%d", &N) != 1) {
        return 1;
    }

    for (i = 0; i < N; i++) {

        if (scanf("%d %d %d %d", &studentId, &score, &totalClasses, &absentClasses) != 4) {
            break;
        }

        if (totalClasses <= 0) {
            printf("Student %d: ERROR\n", studentId);
            continue;
        }

        attendancePercent = (float)(totalClasses - absentClasses) / totalClasses * 100.0;

        if (score >= 50 && attendancePercent >= 75.0) {
            printf("Student %d: PASS\n", studentId);
            passCount++;
        } else {
            failCount++;
            if (score < 50) {
                printf("Student %d: FAIL - Low Score\n", studentId);
            } else {
                printf("Student %d: FAIL - Low Attendance (%.2f%%)\n", studentId, attendancePercent);
            }
        }
    }

    printf("\n--- Summary ---\n");
    printf("Total PASS: %d\n", passCount);
    printf("Total FAIL: %d\n", failCount);

    return 0;
}
