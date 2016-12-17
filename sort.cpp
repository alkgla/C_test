#include <iostream>
void quicksort(int left,int right);
using namespace std;
int a[]={2,4,1,5,8,2,4,1,5,8,3,2,8,2,4,1,5,8,3,2,8,3,2,8},key,i;

int main()
{
	
	int length=sizeof(a)/sizeof(int);
	//≤Â»Î≈≈–Ú	 
/*	for(int j=1;j<length;j++)
	{
		key=a[j];
		i=j-1;
		while(i>=0&&a[i]>key)
		{
			a[i+1]=a[i];
			i=i-1;
		}
		a[i+1]=key;
	}
	
	*/
	//√∞≈›≈≈–Ú
/*	int temp;
	for(int pass=1;pass<length;pass++)
	{
		
		for(i=0;i<length-pass;i++)
		{
			if(a[i]>a[i+1])
			{
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
			}
		}

	}
	*/
	quicksort(0,length-1);

	


	// ‰≥ˆ
	for(i=0;i<length;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
//øÏÀŸ≈≈–Ú∑®
void quicksort(int left,int right)
{

	int i,j,t,temp;
	if(left>right)
		return ;
	temp=a[left];
	i=left;
	j=right;

	while (i!=j)
	{
		while (a[j]>=temp&&i<j)
		{
			j--;
		}
		while(a[i]<=temp&&i<j)
		{
			i++;
		}
		if(i<j)
		{
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	}
	a[left]=a[i];
	a[i]=temp;
	quicksort(left,i-1);
	quicksort(i+1,right);
}