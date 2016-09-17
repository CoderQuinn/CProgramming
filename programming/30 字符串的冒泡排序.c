/*
 我们已经知道了将N个整数按从小到大排序的冒泡排序法。本题要求将此方法用于字符串序列，并对任意给定的K（<N），输出扫描完第K遍后的中间结果序列。
 
 输入格式：
 
 输入在第1行中给出N和K（1≤K<N≤100），此后N行，每行包含一个长度不超过10的、仅由小写英文字母组成的非空字符串。
 
 输出格式：
 
 输出冒泡排序法扫描完第K遍后的中间结果序列，每行包含一个字符串。
 
 输入样例：
 
 6 2
 best
 cat
 east
 a
 free
 day
 输出样例：
 
 best
 a
 cat
 day
 east
 free
 */
#include <stdio.h>
#include <string.h>
#define Max 100

void Bubble(char *str[], int N, int K)
{
    int i, P, flag;
    char *tmp;
    for (P = N-1; P > N-K-1; P--)
    {
        flag = 0;
        for (i = 0; i < P; i++)
            if (strcmp(str[i], str[i+1]) > 0)
            {
                tmp = str[i+1];
                str[i+1] = str[i];
                str[i] = tmp;
                flag = 1;
            }
        if(!flag) // 已经有序的
            break;
    }
}

void Print(char *str[], int n)
{
    int i;
    for (i = 0; i < n; i ++)
        printf("%s\n", str[i]);
}

int main()
{
    int i, N, K;
    char *str[Max];
    char s[Max][11];
    
    scanf("%d %d\n", &N, &K);
    for (i = 0; i < N; i++)
    {
        scanf("%s", s[i]);
        str[i] = s[i];
    }
    Bubble(str, N, K);
    Print(str, N);
    return 0;
}