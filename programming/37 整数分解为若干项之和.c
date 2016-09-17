#include <stdio.h>
#define MaxN 30
int R[MaxN];
int N;
int cnt;

void solve(int r, int begin, int n)
{
    int i;
    if (r == 0)
    {
        cnt++;
        if (cnt%4 != 1)
            printf(";");
        printf("%d=%d", N, R[0]);
        for (i = 1; i < n; i++)
            printf("+%d", R[i]);
        if (cnt%4 == 0)
            printf("\n");
    }
    else
    {
        for (i = begin; i <= r; i++)
        {
            R[n] = i;
            if (i+i <= r || r==i) // begin <= R或者 R==0
                solve(r-i, i, n+1);
        }
    }
}

int main()
{
    cnt = 0;
    scanf("%d", &N);
    solve(N, 1, 0);
    if (cnt%4 != 0)
        printf("\n");
    return 0;
}