/*
 将N个整数按从小到大排序的冒泡排序法是这样工作的：从头到尾比较相邻两个元素，如果前面的元素大于其紧随的后面元素，则交换它们。通过一遍扫描，则最后一个元素必定是最大的元素。然后用同样的方法对前N−1个元素进行第二遍扫描。依此类推，最后只需处理两个元素，就完成了对N个数的排序。
 
 本题要求对任意给定的K（<N），输出扫描完第K遍后的中间结果数列。
 
 输入格式：
 
 输入在第1行中给出N和K（1≤K<N≤100），在第2行中给出N个待排序的整数，数字间以空格分隔。
 
 输出格式：
 
 在一行中输出冒泡排序法扫描完第K遍后的中间结果数列，数字间以空格分隔，但末尾不得有多余空格。
 
 输入样例：
 
 6 2
 2 3 5 1 6 4
 输出样例：
 
 2 1 3 4 5 6
 */

#include <stdio.h>
#define Max 100
void bubbleSort(int A[], int N, int K);
int main()
{
    int i, N, K;
    int A[Max];
    
    scanf("%d %d", &N, &K);
    for (i = 0; i < N; ++i)
        scanf(" %d", &A[i]);
    
    bubbleSort(A, N, K);
    
    for (i = 0; i < N; ++i)
    {
        if (i!=0)
            printf(" ");
        printf("%d", A[i]);
    }

}

void bubbleSort(int A[], int N, int K)
{
    int P, i, tmp;
    for (P = N-1; P>N-K-1; --P)
    {
        for (i = 0; i < P; ++i)
            if (A[i] > A[i+1])
            {
                tmp = A[i+1];
                A[i+1] = A[i];
                A[i] = tmp;
            }
    }
}
