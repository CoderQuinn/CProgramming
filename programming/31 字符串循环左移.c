/*
 输入一个字符串和一个非负整数N，要求将字符串循环左移N次。
 
 输入格式：
 
 输入在第1行中给出一个不超过100个字符长度的、以回车结束的非空字符串；第2行给出非负整数N。
 
 输出格式：
 
 在一行中输出循环左移N次后的字符串。
 
 输入样例：
 
 Hello World!
 2
 输出样例：
 
 llo World!He
 */

/*
 以空间换时间，先将要左移的所有字符放在字符串结尾后，再整体前移N;
 */
#include <stdio.h>
#define Max 201

int main()
{
    char str[Max];
    char c, *p;
    int i, n, l;
    i = l= 0;
    /* read */
    while ((c = getchar()) != '\n')
        str[l++] = c;
    str[l] = '\0';
    
    scanf("%d", &n);
    
    n = n % l;

    if (n != 0)
    {
        p = str;
        while (i < n)
        {
            *(p+l+i) = *(p+i);
            ++i;
        }
        *(p+l+n) = '\0';
        
        i = 0;
        while (*(p+n+i))
        {
            *(p+i) = *(p+n+i);
            ++i;
        }
        *(p+i) = '\0';
    }
    puts(str);
    return 0;
}