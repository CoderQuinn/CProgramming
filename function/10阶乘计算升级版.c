/*
本题要求实现一个打印非负整数阶乘的函数。

函数接口定义：

void Print_Factorial ( const int N );
其中N是用户传入的参数，其值不超过1000。如果N是非负整数，则该函数必须在一行中打印出N!的值，否则打印“Invalid input”。
 
 输入样例：
 
 15
 输出样例：
 
 1307674368000
*/

#include <stdio.h>

void Print_Factorial ( const int N );

int main()
{
    int N;
    
    scanf("%d", &N);
    Print_Factorial(N);
    return 0;
}

void Print_Factorial ( const int N )
{
    int i, j, digitNum;
    int digit[2600] = {0};
    digit[0] = 1; // 用数组第0位模拟个位
    digitNum = 1; // 从个数开始，记录结果总位数
    
    if (N < 0)
    {
        printf("Invalid input");
        return;
    }
    
    if (N == 0)
    {
        printf("1");
        return;
    }
    
    for (i = 2; i <= N; i++)
    {
        
        for (j = 0; j < digitNum; j++)
            digit[j] *= i; // 数组的每一位与i相乘
        for (j = 0; j < digitNum; j++)
            if (digit[j] > 9)
            {
                digit[j+1] += digit[j] / 10; // 每个数组十位数向前进位
                digit[j] = digit[j] % 10;
                if (j == digitNum-1) // 当前的位数已经不够记数了
                    digitNum++;
            }
    }
    for (i = digitNum-1; i >=0; i--)
        printf("%d", digit[i]);
}