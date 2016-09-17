/*
 : ling
 1: yi
 2: er
 3: san
 4: si
 5: wu
 6: liu
 7: qi
 8: ba
 9: jiu
 输入格式：
 
 输入在一行中给出一个整数，如：1234。
 
 提示：整数包括负数、零和正数。
 
 输出格式：
 
 在一行中输出这个整数对应的拼音，每个数字的拼音之间用空格分开，行末没有最后的空格。如 yi er san si。
 
 输入样例：
 
 -600
 输出样例：
 
 fu liu ling ling
 */
#include <stdio.h>

int main()
{
    char in[20];
    char *out;
    char c;
    int i, n;
    i = n = 0;
    while ((c = getchar()) != '\n')
        in[n++] = c;
    while (i < n)
    {
        if (i && in[i-1] != '+') // i != 0,前一位
            printf(" ");
        switch (in[i++])
        {
            case '-':
                out = "fu";
                break;
            case '0':
                out = "ling";
                break;
            case '1':
                out = "yi";
                break;
            case '2':
                out = "er";
                break;
            case '3':
                out = "san";
                break;
            case '4':
                out = "si";
                break;
            case '5':
                out = "wu";
                break;
            case '6':
                out = "liu";
                break;
            case '7':
                out = "qi";
                break;
            case '8':
                out = "ba";
                break;
            case '9':
                out = "jiu";
            default:
                break;
        }
        if (out) // out!=null
            printf("%s", out);
    }
    return 0;
}