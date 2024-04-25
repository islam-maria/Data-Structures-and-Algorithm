#include <stdio.h>
unsigned long long bigmod(unsigned long long b, unsigned long long p, unsigned long long m)
{
    unsigned long long int x, y;
    if (p == 0)
    {
        return 1;
    }
    else if (p % 2 == 0)
    {
        x = 0;
        p = p / 2;
        x = bigmod(b, p, m);
        x = (x * x) % m;
        return x;
    }
    else
    {
        y = 0;
        p = p - 1;
        y = bigmod(b, p, m);
        y = ((b % m) * y) % m;
        return y;
    }
}
int main()
{
    unsigned long long int s, b, p, m, n;
    scanf("%llu", &n);
    while (n != 0)
    {
        int i;
        for (i = 1; i <= n; i++)
        {
            scanf("%llu%llu%llu", &b, &p, &m);
            s = bigmod(b, p, m);
            printf("%llu\n", s);
        }
        scanf("%llu", &n);
    }
    return 0;
}

