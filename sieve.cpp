//ʵ�֡�������ɫ���ɸ�ӡ�
//���룺һ��������n>=2
//���:��������С�ڵ���n������������L
#include <iostream>
#include<math.h>
using namespace std;
int* Sieve(int n, int &length){
	int p=0,j=0,i=0,k=0,q=0;
	int *A = new int[n];
	for(p=2 ; p<n; p++)
		A[p] = p;
	/*�ؼ����裬��p�ı�����������Ϊ0*/
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
	/*��ȡB���г���*/
	for(q=2;q<n;q++)
	{
		if(A[q]!=0)
			i++;
	}
	int *B = new int[i];
	/*��A�ķ�0ֵ����B*/
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