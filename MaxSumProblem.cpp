#include <iostream>
using namespace std;
int MaxSum(int *a,int len);
//最大子段问题 dp
int main(){
	int a[]={-1,3,12,-6,2,5,-7,6,5};
	int len=sizeof(a)/sizeof(int);
	cout<<MaxSum(a,len)<<endl;
}
int MaxSum(int *a,int len){
	int sum=0,b=0;
	for(int i=0;i<len;i++)
	{
		if(b>0)b+=a[i];
		else b=a[i];
		if(b>sum)sum=b;
	}	
	return sum;
}
