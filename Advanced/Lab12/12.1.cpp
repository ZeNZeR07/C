#include <stdio.h>

int *Dijkstra(int *L, int n);

int main() {
    int n = 5, i = 0, j = 0, *d, *g;

    g = new int[n * n];

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            g[i * n + j] = -1;

    g[0 * n + 1] = 100;  g[0 * n + 2] = 80;
    g[0 * n + 3] = 30;   g[0 * n + 4] = 10;
    g[1 * n + 2] = 20;   g[3 * n + 1] = 20;


    g[4 * n + 3] = 10;

    d = Dijkstra(g, n);

    for (i = 0; i < n - 1; i++)
        printf("%d ", d[i]);

    return 0;
}

int *Dijkstra(int *L, int n)
{
    int INF = 1000000000;
    int dist[n];
    int visited[n];

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[0] = 0;

    for (int step = 0; step < n; step++) {
        int u = -1, best = INF;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < best) {
                best = dist[i];
                u = i;
            }
        }

        if (u == -1) break;
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            int w = L[u * n + v];
            if (w != -1 && !visited[v]) {
                int nd = dist[u] + w;
                if (nd < dist[v]) dist[v] = nd;
            }
        }
    }

    int *ans = new int[n - 1];
    for (int i = 1; i < n; i++) ans[i - 1] = dist[i];
    return ans;
}