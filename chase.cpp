/*
------------------׷��chase--------------------
���⣺��������Ϊn����������A0,A1,A2,A3....An-1��
�Լ�����S������ܺͲ�С��S�����������еĳ��ȵ���Сֵ������Ӳ��������0��

�ⷨ������������������������������A(i+1)Ϊ��˵�ĺϷ������Ҷ˵�һ��λ��AiΪ��˵�ĺϷ������Ҷ˵���ҲࣨҲ�п����غϣ���
�����Ϳ���ά��һ���Ҷ˵�ָ�����׷��*/
typedef long  int longint;
#include<iostream>
#include<stdio.h>
#pragma comment(linker, "/STACK:102400000,102400000")  //�ֶ�����ջ�ڴ�
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
