//输入一行长度小于100并且没有空格的字符串， 输出a~z各出现了多少次
#include <iostream>
using namespace std;
int main(){
	char a[100]={0};
	int count[26]={0},i=0;
	char *p=a;
	cin>>p;
	while(a[i]!='\0'){
		++count[(a[i]&31)-1];
		++i;
	}
	i=0;
	while(i<26){
		cout<<count[i]<<" ";
		++i;
	}
	cout<<endl;
}