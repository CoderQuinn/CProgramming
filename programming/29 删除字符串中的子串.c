/*
 输入2个字符串S1和S2，要求删除字符串S1中出现的所有子串S2，即结果字符串中不能包含S2。
 
 输入格式：
 
 输入在2行中分别给出不超过80个字符长度的、以回车结束的2个非空字符串，对应S1和S2。
 
 输出格式：
 
 在一行中输出删除字符串S1中出现的所有子串S2后的结果字符串。
 
 输入样例：
 
 Tomcat is a male ccatat
 cat
 输出样例：
 
 Tom is a male
 */
#include <stdio.h>

char *substr(const char *a, const char *b) // check b is a substring of b or not
{
    int i;
    if (*b) // string b is null or not
    {
        while (*a)
        {
            for (i = 0; *(a+i) == *(b+i); ++i)
            {
                if (*(b+i+1) == '\0') // current == '\0' or not
                    return (char *)a;
            }
            a++;
        }
        return NULL;
    }
    else
        return (char *)a;
}

int stringLen(const char *str)
{
    int len;
    if (*str)
    {
        len = 0;
        while (*str)
        {
            ++len;
            ++str;
        }
        return len;
    }
    else
        return 0;
}

void delete(int l, char *p) // l is the length of substring
{
    while (*(p+l))
    {
        *p = *(p+l);
        ++p;
    }
    *p = '\0';
}

int main()
{
    int i, l;
    char S1[81];
    char S2[81];
    char *t;
    gets(S1);
    gets(S2);
    
    l = stringLen(S2);
    t = substr(S1, S2);
    while (t)
    {
        delete(l, t);
        t = substr(S1, S2);
    }
    printf("%s", S1);
    return 0;
}


