/*
本题要求实现判断给定整数奇偶性的函数。

函数接口定义：

int even( int n );
其中n是用户传入的整型参数。当n为偶数时，函数返回1；n为奇数时返回0。注意：0是偶数。

裁判测试程序样例：

输入样例1：

-6
输出样例1：

-6 is even.
*/

#include <stdio.h>

int even( int n );

int main()
{
    int n;
    
    scanf("%d", &n);
    if (even(n))
        printf("%d is even.\n", n);
    else
        printf("%d is odd.\n", n);
    
    return 0;
}

int even( int n )
{
    int num = n > 0 ? (n : (-1) * n);
    return !(num % 2);
}
