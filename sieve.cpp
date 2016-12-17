//实现“埃拉托色尼的筛子”
//输入：一个正整数n>=2
//输出:包含所有小于等于n的质数的数组L
#include <iostream>
#include<math.h>
using namespace std;
int* Sieve(int n, int &length){
	int p=0,j=0,i=0,k=0,q=0;
	int *A = new int[n];
	for(p=2 ; p<n; p++)
		A[p] = p;
	/*关键步骤，把p的倍数的数消掉为0*/
	for(p=2; p<=sqrt(n); p++)
	{
		if(A[p]!=0)
			j= p*p;
		while(j<=n)
		{
			A[j]=0;
			j=j+p;
		}
	}
	/*获取B数列长度*/
	for(q=2;q<n;q++)
	{
		if(A[q]!=0)
			i++;
	}
	int *B = new int[i];
	/*将A的非0值赋予B*/
	for(p=2; p<n; p++)
	{
		if(A[p]!=0)
		{
			B[k]=A[p];
			k++;
		}
	}
		length = i;
		return B;
	}
int main()
{
	int length =0;
	int *R = Sieve(100,length);
	for(int i=0;i<length;i++)
		cout << R[i] << "\t";
	cout << endl;
	return 0;
}