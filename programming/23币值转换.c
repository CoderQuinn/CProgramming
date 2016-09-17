/*
 输入一个整数（位数不超过9位）代表一个人民币值（单位为元），请转换成财务要求的大写中文格式。如23108元，转换后变成“贰万叁仟壹百零捌”元。为了简化输出，用小写英文字母a-j顺序代表大写数字0-9，用S、B、Q、W、Y分别代表拾、百、仟、万、亿。于是23108元应被转换输出为“cWdQbBai”元。
 
 输入格式：
 
 输入在一行中给出一个不超过9位的非负整数。
 
 输出格式：
 
 在一行中输出转换后的结果。注意“零”的用法必须符合中文习惯。
 
 输入样例1：
 
 813227345
 输出样例1：
 
 iYbQdBcScWhQdBeSf
 输入样例2：
 
 6900
 输出样例2：
 
 gQjB
-------------------------------
 四位处理思路，比如千万到万这四位
 亿位不为0,输出‘a’的case:
 一.千位为0:
    1.千位百位为0,十位不为0;
    2.千位百位十位为0,个位不为0;
    3.千位为0,百位不为0;
 二.百位为0:
    1.千位十位不为0;
    2.百位十位为0，千位个位不为0
 三.十位为0:
    1.百位个位不为0

 亿位为0,输出‘a’的case:
 二.百位为0:
    1.千位十位不为0;
    2.百位十位为0，千位个位不为0
 三.十位为0:
    1.百位个位不为0
 -------------------------------
 */
#include <stdio.h>
#define Max 9
static char units[5] = {'S', 'B', 'Q', 'W', 'Y'};
static char wFigure[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};

void SettleFour(int A[], int start, int end, int preIsZero)
{
    int i;
    for (i = end; i > start; i--)
    {
        if (A[i])
            printf("%c%c", wFigure[A[i]], units[i%4-1]);
        else if (i == end && !preIsZero && ((A[end-1]) || (!A[end -1] && A[end-2]) || (!A[end-1] && !A[end-2] && A[end-3])) ) // 千位是否为0; 千位为0，再判断千位的前四位是否为0; 千位为0, 标记位为No后，再判断思路一中的情况
                printf("a");
        else if(i == end-1 && ((A[end] && A[end-2]) || (A[end] && A[end-3] && !A[end-2]))) // 百位是否为0; 百位为0后，再判断思路二中的情况
                printf("a");
        else if(i == end-2 && (A[end-1] && A[end-3]) ) // 十位是否为0; 十位为0后，再判断思路三中的情况
            printf("a");
    }
    if (A[i]) // 个位不为0;
        printf("%c", wFigure[A[i]]);
}

void Switch(int A[]) // 处理n!=0的转换
{
    int i;
    int yIsZero, wIsZero;
    yIsZero = wIsZero = 0; // 初始化，亿位，千万~万位不是0;
    for (i = 0; i < 3; i++)
        if (i == 0)
        {
            if(A[8])
                printf("%c%c", wFigure[A[8]], units[4]);
            else
                yIsZero = 1; // 亿位为0
        }
        else if(i == 1)
        {
            if (!A[7] && !A[6] && !A[5] && !A[4]) // 从万位到千万全为0
            {
                wIsZero = 1; // 千万到万标记位
                if (!yIsZero) // 亿位不为0，要输出零
                    printf("a");
            }
            else
            {
                SettleFour(A, 4, 7, yIsZero);
                printf("W");
            }
        }
        else // 个位到千位
            SettleFour(A, 0, 3, wIsZero);
}

int main()
{
    int i, n, tmp;
    int inOrder[Max]; // 将输入数字的每一位存进数组，等于0用0补齐
    scanf("%d", &n);
    if(n == 0)
    {
        printf("a");
        return 0;
    }
    i = 0;
    tmp = n;
    while (i < Max)
    {
        inOrder[i++] = tmp  % 10;
        tmp = tmp / 10;
    }
    Switch(inOrder);
    return 0;
}