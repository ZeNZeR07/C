#include <stdio.h>

int *KnapsackGreedy(int *w, int *v, int n, int wx);

int main() {
    int n = 5, wx = 11;
    int w[5] = { 1, 2, 5, 6, 7 };
    int v[5] = { 1, 6, 18, 22, 28 };

    int *x = KnapsackGreedy(w, v, n, wx);

    for (int i = 0; i < n; i++)
        printf("%d ", x[i]);

    return 0;
}

int *KnapsackGreedy(int *w, int *v, int n, int wx)
{
    int *x = new int[n];
    int usedW = 0;

    for (int i = 0; i < n; i++)
        x[i] = 0;

    int idx[n];
    for (int i = 0; i < n; i++)
        idx[i] = i;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (v[idx[j]] < v[idx[j + 1]]) {
                int temp = idx[j];
                idx[j] = idx[j + 1];
                idx[j + 1] = temp;
            }
        }
    }

    for (int k = 0; k < n; k++) {
        int i = idx[k];
        if (usedW + w[i] <= wx) {
            x[i] = 1;
            usedW += w[i];
        }
    }

    return x;
}