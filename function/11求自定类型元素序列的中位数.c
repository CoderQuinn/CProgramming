/*
本题要求实现一个函数，求N个集合元素A[]的中位数，即序列中第⌈N/2⌉大的元素。其中集合元素的类型为自定义的ElementType。

函数接口定义：

ElementType Median( ElementType A[], int N );
其中给定集合元素存放在数组A[]中，正整数N是数组元素个数。该函数须返回N个A[]元素的中位数，其值也必须是ElementType类型。
 
输入样例：
3
12.3 34 -5
输出样例：

12.30
*/
#include <stdio.h>

#define MAXN 10
typedef float ElementType;

/** 法一 **/
void Swap(ElementType *a, ElementType *b)
{
    ElementType t;
    t = *a;
    *a = *b;
    *b = t;
}
ElementType Median3( ElementType A[], int left, int right )
{
    int center;
    center = (left+right)/2;
    if (A[left] > A[center])
        Swap(&A[left], &A[center]);
    if (A[left] > A[right])
        Swap(&A[left], &A[right]);
    if (A[center] > A[right])
        Swap(&A[center], &A[right]);
    Swap(&A[center], &A[right-1]);
    return A[right-1];
}

void QuickSort(ElementType A[], int left, int right)
{
    int low, high;
    ElementType pivot;
    
    if (left >= right)
        return; // 递归出口
    
    pivot = Median3(A, left, right);
    low = left;
    high = right-1;
    while (1)
    {
        while (low < high && A[++low] < pivot);
        while (low < high && A[--high] > pivot);
        if (low < high)
            Swap(&A[low], &A[high]);
        else
            break;
    }
    Swap(&A[low], &A[right-1]);
    QuickSort(A, left, low-1);
    QuickSort(A, low+1, right);
}

ElementType Median( ElementType A[], int N )
{
    ElementType ret;
    int K;
    K = N/2;
    QuickSort(A, 0, N-1);
    return A[K];
}


/** 法二 **/
void Swap(ElementType *a, ElementType *b)
{
    ElementType t;
    t = *a;
    *a = *b;
    *b = t;
}
ElementType Median3( ElementType A[], int left, int right )
{
    int center;
    center = (left+right)/2;
    if (A[left] < A[center])
        Swap(&A[left], &A[center]);
    if (A[left] < A[right])
        Swap(&A[left], &A[right]);
    if (A[center] < A[right])
        Swap(&A[center], &A[right]);
    Swap(&A[center], &A[right-1]);
    return A[right-1];
}
ElementType FindKthLargest(ElementType A[], int K, int left, int right)
{
    
    int low, high;
    ElementType pivot;
    pivot = Median3(A, left, right);
    
    if (left >= right)
        return pivot; // 递归出口
    low = left;
    high = right-1;
    while (1)
    {
        while (low < high && A[++low] > pivot);
        while (low < high && A[--high] < pivot);
        if (low < high)
            Swap(&A[low], &A[high]);
        else
            break;
    }
    Swap(&A[low], &A[right-1]);
    if (low-left+1 > K)
        return FindKthLargest(A, K, left, low-1);
    else if(low-left+1 < K)
        return FindKthLargest(A, K-low+left-1, low+1, right);
    else
        return pivot;
}

ElementType Median( ElementType A[], int N )
{
    ElementType ret;
    int K;
    K = (N+1)/2;
    ret = FindKthLargest(A, K, 0, N-1);
    return ret;
}


int main ()
{
    int N, i;
    ElementType A[MAXN];
    
    scanf("%d", &N);
    for ( i=0; i<N; i++ )
        scanf("%f", &A[i]);
    printf("%.2f\n", Median(A, N));
    return 0;
}

