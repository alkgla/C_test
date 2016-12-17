/*
    动态规划
    PRO: 一个序列有N个数：A[1],A[2],…,A[N]，求出最长非降子序列的长度。
       
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream.h>
int DPLIS(int Arr[], int n)
{
    int iterx = 0, itery = 0;
    int maxVal = 0;
    int *d = (int *)malloc(sizeof(int) * n);
    memset(d, 0, sizeof(int) * n);
    for(iterx = 0; iterx < n; iterx++ )
    {
        d[iterx] = 1;
        for(itery = 0; itery < iterx; itery++)
        {
            if(Arr[iterx] >= Arr[itery])
            {
                d[iterx] = d[iterx] > d[itery] + 1 ? d[iterx] : d[itery] + 1;
            }
        }
        if(maxVal < d[iterx])
        {
            maxVal = d[iterx];
        }
    }
    free(d);
    return maxVal;
}
int main(void)
{
    int Arr[100] = {4, 5,3 ,3 ,3 ,3 ,6 ,5 ,1 ,2};
    int n = 10;
 
    printf("the result is %d\n",DPLIS(Arr, n));
    return 0;
}