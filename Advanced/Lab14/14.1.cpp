#include <stdio.h>

int KnapsackBT(int *w, int *v, int n, int wx, int i, int *x);

static void copyArr(int *dst, int *src, int n)
{
    for (int k = 0; k < n; k++) dst[k] = src[k];
}

static int bt(int *w, int *v, int n, int wx, int i,
              int curW, int curV, int *curX, int *bestX)
{
    if (i == n) {
        copyArr(bestX, curX, n);
        return curV;
    }

    // ทางเลือก 1: ไม่เอาชิ้น i
    curX[i] = 0;
    int bestV = bt(w, v, n, wx, i + 1, curW, curV, curX, bestX);

    // ทางเลือก 2: เอาชิ้น i (ถ้ายังไม่เกิน wx)
    if (curW + w[i] <= wx) {
        int tmpBestX[n];
        copyArr(tmpBestX, bestX, n);

        curX[i] = 1;
        int takeV = bt(w, v, n, wx, i + 1,
                       curW + w[i], curV + v[i],
                       curX, tmpBestX);

        if (takeV > bestV) {
            bestV = takeV;
            copyArr(bestX, tmpBestX, n);
        }
    }

    return bestV;
}

int KnapsackBT(int *w, int *v, int n, int wx, int i, int *x)
{
    int curX[n];
    int bestX[n];

    for (int k = 0; k < n; k++) {
        curX[k] = 0;
        bestX[k] = 0;
        x[k] = 0;
    }

    int bestV = bt(w, v, n, wx, i, 0, 0, curX, bestX);
    copyArr(x, bestX, n);
    return bestV;
}

int main() {
    int n = 5, wx = 11;
    int w[5] = { 1, 2, 5, 6, 7 };
    int v[5] = { 1, 6, 18, 22, 28 };
    int *x, vx;

    x = new int[n];
    vx = KnapsackBT(w, v, n, wx, 0, x);

    printf("Value = %d\n", vx);
    for (int i = 0; i < n; i++) printf("%d", x[i]);
    return 0;
}