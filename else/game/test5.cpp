/*
//输入两行只包含字母和数字的字符串, 第一行A, 第二行B，计算B在A中出现了多少次(忽略大小写)
#include <iostream>
#include <string>
using namespace std;
int count=0;
int main(){
	string A,B;
	int a[50]={0},b[50]={0};
	cin>>A>>B;
	int a1=A.size();
	int a2=B.size();
	while(a1--){
		if(A[a1]>='0'||A[a1]<='9')
			++a[A[a1]&15];
		else
		{
			A[a1]=A[a1]|32;//转化小写
			++a[(A[a1]&31)+9];
		}
	}
	while(a2--){
		if(B[a2]>='0'||B[a2]<='9')
			++b[B[a2]&15];
		else
		{
			B[a2]=B[a2]|32;
			++b[(B[a2]&31)+9];
		}
	}
	//判断
	int i=0;
	while(i<50){
			if(a[i]>b[i])
				count=count+b[i];
			else
				count=count+a[i];
			++i;

	}
	cout<<count<<endl;

}*/

//输入两行只包含字母和数字的字符串, 第一行A, 第二行B，计算B在A中出现了多少次(忽略大小写)

#include <stdio.h>
int i, j, cnt;
char a[2048], b[2048];
int main() {
	gets(a);
	gets(b);
	for(i = 0; a[i]; ++i) {
		for(j = 0; b[j] && (b[j]&31)==(a[i+j]&31); ++j) {}
		cnt += !b[j];
	}
	printf("%d\n", cnt);
	return 0;
}


