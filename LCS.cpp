#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1001 // Renamed max to MAX_LENGTH
char a[MAX_LENGTH], b[MAX_LENGTH];
int dp[MAX_LENGTH][MAX_LENGTH];
char visited[MAX_LENGTH][MAX_LENGTH];

int maximum(int a, int b) // Renamed max to maximum
{
    return (a > b) ? a : b;
}

int lcs(int i, int j)
{
    if (a[i] == '\0' || b[j] == '\0')
        return 0;
    if (visited[i][j])
        return dp[i][j];
    int ans = 0;
    if (a[i] == b[j])
        ans = 1 + lcs(i + 1, j + 1);
    else
        ans = maximum(lcs(i, j + 1), lcs(i + 1, j));
    visited[i][j] = 1;
    dp[i][j] = ans;
    return dp[i][j];
}

int main()
{
    while (gets(a) && gets(b))
    {
        memset(visited, 0, sizeof(visited));
        printf("%d\n", lcs(0, 0));
    }
    return 0;
}
