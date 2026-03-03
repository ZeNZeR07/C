#include <stdio.h>

static int maxInt(int a, int b)
{
    return (a > b) ? a : b;
}

static void buildDPTable(int dp[][12], int *weights, int *values, int itemCount, int capacity)
{
    for (int i = 0; i <= itemCount; i++) {
        for (int c = 0; c <= capacity; c++) {
            if (i == 0 || c == 0) {
                dp[i][c] = 0;
                continue;
            }

            int notTake = dp[i - 1][c];
            int take = -1;

            if (weights[i - 1] <= c) {
                take = values[i - 1] + dp[i - 1][c - weights[i - 1]];
            }

            dp[i][c] = maxInt(notTake, take);
        }
    }
}

static void reconstructChoice(int *x, int dp[][12], int *weights, int itemCount, int capacity)
{
    for (int i = 0; i < itemCount; i++) {
        x[i] = 0;
    }

    int c = capacity;
    for (int i = itemCount; i >= 1; i--) {
        if (dp[i][c] != dp[i - 1][c]) {
            x[i - 1] = 1;
            c -= weights[i - 1];
        }
    }
}

int *KnapsackDP(int *w, int *v, int n, int wx)
{
    int dp[6][12];

    buildDPTable(dp, w, v, n, wx);

    int *x = new int[n];
    reconstructChoice(x, dp, w, n, wx);

    return x;
}

int main()
{
    int n = 5;
    int wx = 11;
    int w[5] = { 1, 2, 5, 6, 7 };
    int v[5] = { 1, 6, 18, 22, 28 };
    int *x = KnapsackDP(w, v, n, wx);

    for (int i = 0; i < n; i++) {
        printf("%d ", x[i]);
    }

    return 0;
}