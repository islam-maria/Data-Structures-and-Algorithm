#include <stdio.h>
#include <string.h>

int main()
{
    char n[100000], x[100000], y = NULL;
    int length1 = 0, i = 0, j = 0, k = 0, m = 0, length = 0, count = 0;
    while (scanf("%s%s", n, x) == 2)
    {
        length1 = strlen(n);
        length = strlen(x);
        if (length1 > length)
           printf("No\n");
        else
        {
            for (int i = 0; i < length1; i++)
            {
                for (j = m; j < length; j++)
                {
                    if (n[i] == x[j])
                    {
                        m = j + 1;
                        count++;
                        break;
                    }
                }
            }
            if (count == length1)
               printf("Yes\n");
            else
               printf("No\n");
        }
        count = 0;
        m = 0;
    }
    return 0;
}