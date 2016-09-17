/*
表格输出   (5分)
本题要求编写程序，按照规定格式输出表格。

输入格式：

本题目没有输入。

输出格式：

要求严格按照给出的格式输出下列表格：

------------------------------------
Province      Area(km2)   Pop.(10K)
------------------------------------
Anhui         139600.00   6461.00
Beijing        16410.54   1180.70
Chongqing      82400.00   3144.23
Shanghai        6340.50   1360.26
Zhejiang      101800.00   4894.00
------------------------------------
*/
#include <stdio.h>

struct Province
{
    char name[10];
    float area;
    float pop;
};
void printLine()
{
    int i;
    for (i = 0; i < 36; i++)
        printf("-");
    printf("\n");
}
/*
------------------------------------
Province      Area(km2)   Pop.(10K)
------------------------------------
Anhui         139600.00   6461.00
Beijing        16410.54   1180.70
Chongqing      82400.00   3144.23
Shanghai        6340.50   1360.26
Zhejiang      101800.00   4894.00
------------------------------------
 */
int main()
{
    printf("------------------------------------\n");
    printf("Province      Area(km2)   Pop.(10K)\n");
    printf("------------------------------------\n");
    printf("Anhui         139600.00   6461.00\n");
    printf("Beijing        16410.54   1180.70\n");
    printf("Chongqing      82400.00   3144.23\n");
    printf("Shanghai        6340.50   1360.26\n");
    printf("Zhejiang      101800.00   4894.00\n");
    printf("------------------------------------\n");
    return 0;
}