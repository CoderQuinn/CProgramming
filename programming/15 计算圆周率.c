/*
 根据下面关系式，求圆周率的值，直到最后一项的值小于给定阈值。
 
 输入格式：
 
 输入在一行中给出小于1的阈值。
 
 输出格式：
 
 在一行中输出满足阈值条件的近似圆周率，输出到小数点后6位。
 
 输入样例：
 
 0.01
 输出样例：
 
 3.132157
 */
#include <stdio.h>

int main()
{
    int i, j;
    float thr, tmp, pi;
    i = 0;
    pi = 2.0;
    scanf("%f", &thr);
    do
    {
        tmp = 1.0;
        j = ++i;
        while (j)
        {
            tmp *= 1.0*j/(2*j+1);
            j--;
        }
        pi += (2.0*tmp);
    } while (tmp >= thr);
    
    printf("%.6f", pi);
    return 0;
}
