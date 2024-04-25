#include <stdio.h>
#include <string.h>

int main()
{
    int t, i, j;
    char a[300], b[300];
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s %s", a, b);
        int lengthA = strlen(a), lengthB = strlen(b);
        int sum[300] = {};
        for (i = 0; i < lengthA; i++)
            sum[i] += a[i] - '0';
        for (i = 0; i < lengthB; i++)
            sum[i] += b[i] - '0';
        int lengthC = lengthA > lengthB ? lengthA : lengthB;
        for (j = 0; j <= lengthC + 1; j++)
        {
            sum[j + 1] += sum[j] / 10;
            sum[j] %= 10;
        }
        for (j = lengthC + 1; j >= 0; j--)
        {
            if (sum[j])
                break;
        }
        if (j < 0)
            j++;
        i = 0;
        while (sum[i] == 0)
            i++;
        while (i <= j)
            printf("%d", sum[i++]);
        puts("");
    }
    return 0;
}