/*
程序每次读入一个正3位数，然后输出按位逆序的数字。注意：当输入的数字含有结尾的0时，输出不应带有前导的0。比如输入700，输出应该是7。

输入格式：

每个测试是一个3位的正整数。

输出格式：

输出按位逆序的数。

输入样例：

123
输出样例：

321
*/
#include <stdio.h>
int reverseThreeFigures(int threeFigures)
{
    if (threeFigures < 100) return -1;
    int newUnits, newTens, newHundreds, tmp, new;
    tmp = threeFigures;
    
    newUnits = tmp / 100;
    tmp = tmp % 100;
    newTens = tmp / 10;
    newHundreds = tmp % 10;
    
    new = newUnits + 10 * newTens + 100 * newHundreds;
    return new;
}

int main()
{
    int num, newNum;
    scanf("%d", &num);
    
    newNum = reverseThreeFigures(num);
    printf("%d", newNum);
    return 0;
}
