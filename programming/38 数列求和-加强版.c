#include <stdio.h>
#define Max 1000001
/*
int main()
{
    int i, j, A, N;
    int digit[Max] = {0};
    int totlaNum;
    
    scanf("%d %d", &A, &N);
    if (N == 0)
    {
        printf("0");
        return 0;
    }
    digit[0] = A;
    totlaNum = 1; // 记录结果的总位数,初始为N位
    
    for (i = 1; i < N; i++)
    {
        for (j = 0; j <= i; j++) // 每一位加A
            digit[j] += A;
        totlaNum++;
        if (digit[totlaNum-1] > 9)
            totlaNum++;
        for (j = 0; j < totlaNum; j++)
        {
            if (digit[j] > 9)
            {
                digit[j+1] += digit[j] / 10; // 每个数组满10向前进位
                digit[j] %= 10; // 进位后取余
            }
        }
    }
    for (i = totlaNum-1; i >= 0; i--)
        printf("%d", digit[i]);
    printf("\n");
    
    return 0;
}
*/
int main()
{
    int i, j, A, N;
    int tmp, Q;
    int D[Max] = {0};
    
    scanf("%d %d", &A, &N);
    
    if (N == 0)
    {
        printf("0");
        return 0;
    }
    j = 0; // 从个位开始，每一项的A相加;
    Q = 0; // 下位向上一位的进位值
    for (i = N; i >= 1; --i)
    {
        tmp = A * i + Q; // 每一次相加的A要减少一个，并且需要加上上一次的进位
        D[j] = tmp % 10;
        Q = tmp / 10;
        ++j;
    }
    
    if (Q > 0)
        D[j] = Q;
    else
        --j;
    for (i = j; i >= 0; i--)
        printf("%d", D[i]);
}