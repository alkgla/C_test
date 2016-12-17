// 输入两个32位十进制整数， 一行一个， 输出他们的和
/*
#include <iostream>
using namespace std;
int temp=0;
int main(){
char a[10]={'0'},b[10]={'0'},sum[10]={'0'};
int i=0;
char *p=sum;
cout<<"请输入两个3位数字\n第一个：\n";
for(i=0;i<3;i++){
cin>>a[i];
}
cout<<"第二个：\n";
for(i=0;i<3;i++){
cin>>b[i];
}
//两个数相加
int count=2;
while(count>=0){
sum[count+1]=(((a[count]-'0')+(b[count]-'0')+temp)%10+'0');
temp=((a[count]-'0')+(b[count]-'0')+temp)/10;
--count;
}
if((temp)!=0)
sum[count+1]=temp+'0';
else
++p;
cout<<"结果是:"<<p<<endl;
}


// 输入两个32位十进制整数， 一行一个， 输出他们的和
#include <stdio.h>
#include <string.h>

const int N = 128;

int i, s, c;
char a[N], b[N];

int main() {
	scanf("%s %s", a, b);
	strrev(a);//反转字符串
	strrev(b);
	for(i = 0; a[i]||b[i]||c; ++i) {
		s = (a[i]&15)+(b[i]&15)+c;
		a[i] = s%10+'0';
		c = s/10;
	}
	strrev(a);
	puts(a);
	return 0;
}*/

// 输入两个32位十进制整数， 一行一个， 输出他们的和
#include <iostream>
using namespace std;
int temp=0;
int main(){
	char a[10]={'0'},b[10]={'0'},sum[10]={'0'};
	int i=0;
	char *p=sum;
	cout<<"请输入两个3位数字\n第一个：\n";
	for(i=0;i<3;i++){
		cin>>a[i];
	}
	cout<<"第二个：\n";
	for(i=0;i<3;i++){
		cin>>b[i];
	}
	//两个数相加
	int count=2;
	while(count>=0){
		sum[count+1]=(((a[count]-'0')+(b[count]-'0')+temp)%10+'0');
		temp=((a[count]-'0')+(b[count]-'0')+temp)/10;
		--count;
	}
	if((temp)!=0)
		sum[count+1]=temp+'0';
	else
		++p;
	cout<<"结果是:"<<p<<endl;
}
