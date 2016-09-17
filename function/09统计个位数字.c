/*
本题要求实现一个函数，可统计任一整数中某个位数出现的次数。例如-21252中，2出现了3次，则该函数应该返回3。

函数接口定义：

int Count_Digit ( const int N, const int D );
其中N和D都是用户传入的参数。N的值不超过int的范围；D是[0, 9]区间内的个位数。函数须返回N中D出现的次数。

 输入样例：
 
 -21252 2
 输出样例：
 
 3
*/
#include <stdio.h>

int Count_Digit ( const int N, const int D );

int main()
{
    int N, D;
    
    scanf("%d %d", &N, &D);
    printf("%d\n", Count_Digit(N, D));
    return 0;
}

int Count_Digit ( const int N, const int D )
{
    int R, Q, cnt;
    cnt = 0;
    
    if (N == 0)
    {
        if (D == N) return 1;
    }
    else
        Q = (N>0 ? N : -1*N);

    while (Q)
    {
        R = Q % 10;
        if (D == R)
            ++cnt;
        Q /= 10;
    }
    return cnt;
}