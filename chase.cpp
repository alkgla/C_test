/*
------------------追逐法chase--------------------
题意：给定长度为n的数列整数A0,A1,A2,A3....An-1，
以及整数S，求出总和不小于S的连续子序列的长度的最小值。如果接不存在输出0。

解法：给出的整数都是正整数，所有以A(i+1)为左端点的合法区间右端点一定位于Ai为左端点的合法区间右端点的右侧（也有可能重合），
这样就可以维护一个右端点指针进行追逐。*/
typedef long  int longint;
#include<iostream>
#include<stdio.h>
#pragma comment(linker, "/STACK:102400000,102400000")  //手动扩大栈内存
using namespace std;
int n,s;
int num[100010];
int min(int a,int b){
	return a>b?b:a;
};
int main(){
	int t,i;
	cin>>t;
	while(t--){
		scanf("%d%d",&n,&s);
		//printf("%d %d\n",n,s);
		for(i=0;i<n;i++)
			scanf("%d",num+i);
		int ans=n;
		int right=0;
		longint sum=0;
		bool flag=0;
		
		for(i=0;i<n;i++){
			if(i>=1)
				sum-=num[i-1];
			while(sum<s&&right<n)
				sum+=num[right++];
			if(sum<s)
				break;
			ans=min(ans,right-i);
			flag=1;
		}
		if(flag)  
			cout<<ans<<endl;  
		else cout<<"0"<<endl;  
	}
}
