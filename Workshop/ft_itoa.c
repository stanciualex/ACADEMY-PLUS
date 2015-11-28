#include "header.h"

static int reversen(int n)
{
    int nr;

    nr = 0;
    while (n)
    {
        nr = 10 * nr + n % 10;
        n = n / 10;
    }
    return nr;
}

static int numlen(int n)
{
    int len;

    len = 0;
    while (n)
    {
        len++;
        n /= 10;
    }
    return len;
}

char    *ft_itoa(int n)
{
    int neg;
    int i;
    int len;
    char *str;

    i = 0;
    neg = 0;
    if (n < 0)
    {
        neg = 1;
        n = -n;
    }
    n = reversen(n);
    len = numlen(n);
    str = (char *)malloc(sizeof(*str) * (len + 1));
    if (neg)
    {
        str[i] = '-';
        i++;
    }
    while (n)
    {
        str[i] = (n % 10) + '0';
        n = n / 10;
        i++;
    }
    str[i] = '\0';
    return (str);
}
