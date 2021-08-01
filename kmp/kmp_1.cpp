#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;

int *buildNext(char *P)
{
    int m = strlen(P);
    int j = 0;
    int *next = new int[m];
    int t = next[0] = -1;
    while (j < m - 1)
    {
        if (t < 0 || P[j] == P[t])
        {
            ++j;
            ++t;
            //            next[j] = t;
            next[j] = (P[j] != P[t] ? t : next[t]);
        }
        else
        {
            t = next[t];
        }
    }
    return next;
}
int kmp_match(char *P, char *T)
{
    int *next = buildNext(P);
    int n = strlen(T), i = 0;
    int m = strlen(P), j = 0;
    while (j < m && i < n)
    {
        if (j < 0 || T[i] == P[j])
        {
            ++i;
            ++j;
        }
        else
        {
            j = next[j];
        }
    }
    delete[] next;
    return j == m ? (i - j) : -1;
}

int main()
{
    char b[128] = "ababcabcacbab";
    char a[128] = "tr";
    cout << kmp_match(a, b) << endl;
    return 0;
}