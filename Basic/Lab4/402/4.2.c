#include <stdio.h>

int main() {
    int N, i;
    int passSum = 0;
    int failCount = 0;


    if (scanf("%d", &N) != 1) {
        return 1;
    }

    int scores[N];


    for (i = 0 ; i < N; i++) {
        if (scanf("%d", &scores[i]) != 1) {
            return 1;
    }

    if (scores[i] >= 50) {
            passSum += scores[i];
        } else {
            failCount++;
        }
    }

    printf("Passing Score Sum: %d\n", passSum);
    printf("Failing Students Count: %d\n", failCount);


    return 0;

    
}