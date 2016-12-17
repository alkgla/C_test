//找出所有这样的3位数， 他们的平方每个数字都是奇数
//平方各位数都是奇数很困难

/*#include <iostream>
#include <math.h>
using namespace std;
int i,n,b;
int main(){
	char s[20];
	for(int a=100;a<=999;++a)
	{
		n=a*a;
		itoa(n,s,20);
		for(i=0;s[i]!='\0';++i);
		for(b=0;b<i;b++){
			if(s[b]%2==0)
				break;
		}
		if(b==i)
			cout<<a<<endl;
	}
}

*/
#include<stdio.h>

int main() {
	int i, j;
	char s[64];
	for(i = 100; i < 1000; ++i) {
		sprintf(s, "%d", i*i);
		for(j = 0; s[j]; ++j) if(!(s[j]&1)) break;
		if(!s[j]) printf("%d %d\n", i, i*i);
	}
	return 0;
}