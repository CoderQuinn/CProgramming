/*
 你的程序要读入一行文本，其中以空格分隔为若干个单词，以.结束。你要输出每个单词的长度。这里的单词与语言无关，可以包括各种符号，比如it's算一个单词，长度为4。注意，行中可能出现连续的空格；最后的.不计算在内。
 
 输入格式：
 
 输入在一行中给出一行文本，以.结束
 
 提示：用scanf("%c",...);来读入一个字符，直到读到.为止。
 
 输出格式：
 
 在一行中输出这行文本对应的单词的长度，每个长度之间以空格隔开，行末没有最后的空格。
 
 输入样例：
 
 It's great to see you here.
 输出样例：
 
 4 5 2 3 3 4
 */
#include <stdio.h>

int main()
{
    char c;
    int i, cnt, is1thSpace;
    cnt = 0;
    is1thSpace = 0;
    i = 0;
    do
    {
        c = getchar();
        if (c == ' ')
        {
            if (is1thSpace) // 遇到第一个空格，则输出
            {
                if (i++) // 是否第一次输出
                    printf(" ");
                printf("%d", cnt);
                cnt = 0;
                is1thSpace = 0;
            }
        }
        else if(c != '.') // 不为空格，是否为结束符
        {
            cnt++;
            is1thSpace = 1;
        }
        else // c == '.'
        {
            if (is1thSpace)
            {
                if (i++) // 是否第一次输出
                    printf(" ");
                printf("%d", cnt);
            }
        }
    } while (c != '.');
    return 0;
}
void test()
{
//        if (c != ' ' && c != '.')
//        {
//            cnt++;
//            is1thSpace = 1;
//        }
//        else if((c == '.' && is1thSpace) || is1thSpace)
//        {
//            if (i++)
//                printf(" ");
//            printf("%d", cnt);
//            cnt = 0;
//            is1thSpace = 0;
//        }
}