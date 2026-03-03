#include <stdio.h>

int *KnapsackDP(int *w, int *v, int n, int wx);

int main() {
    int n = 5, wx = 11;
    int w[5] = { 1, 2, 5, 6, 7 };
    int v[5] = { 1, 6, 18, 22, 28 };
    int *x;

    x = KnapsackDP(w, v, n, wx);
    for (int i = 0; i < n; i++) printf("%d ", x[i]);

    return 0;
}

int *KnapsackDP(int *w, int *v, int n, int wx)
{
    int dp[n + 1][wx + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= wx; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else {
                int notTake = dp[i - 1][j];
                int take = -1;

                if (w[i - 1] <= j) {
                    take = v[i - 1] + dp[i - 1][j - w[i - 1]];
                }

                dp[i][j] = (take > notTake) ? take : notTake;
            }
        }
    }

    int *x = new int[n];
    for (int i = 0; i < n; i++) x[i] = 0;

    int j = wx;
    for (int i = n; i >= 1; i--) {
        if (dp[i][j] != dp[i - 1][j]) {
            x[i - 1] = 1;
            j -= w[i - 1];
        }
    }

    return x;
}