#include <stdio.h>
#define MAX_NODES 200
int graph[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];
int flag;
void init(int n) {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
}
void dfs(int node, int color, int n) {
    visited[node] = color;
    for (int neighbor = 0; neighbor < n; neighbor++) {
        if (graph[node][neighbor]) {
            if (visited[neighbor] == 0) {
                dfs(neighbor, 3 - color, n);
            } else if (visited[neighbor] == color) {
                flag = -1;
                return;
            }
        }
    }
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d %d", &n, &m);
        init(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            graph[u][v] = graph[v][u] = 1;
        }
        int ans = 0;
        flag = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                dfs(i, 1, n);
                ans++;
            }
        }
        if (flag == -1) {
            printf("-1\n");
        } else {
            printf("%d\n", ans);
        }
    }
    return 0;
}
