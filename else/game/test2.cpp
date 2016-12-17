//有一个变量a=1234, 每次增加6789，超过或等于1000000就减去1000000, 问增加多少次后出现重复的a
/*
#include <iostream>
using namespace std;
int q[1000000]={0};
int main(){
	int a=1234;
	int n=0;
	while(1){
		++q[a];
		if(q[a]==2)
			break;
		a=a+6789;
		if(a>=1000000){
			a=a-1000000;
		}
		++n;
	}
	cout<<n<<endl;
}*/

#include<stdio.h>

const int m = 1000000;

bool b[m];

int main() {
  int n = 1234, c = 0;
  while(!b[n]) {
    b[n] = true;
	++c;
	n = (n+6789)%m;
  }
  printf("%d\n", c);
  return 0;
}

/*
  问题重述一下, 变量a每次加b除以c取余数, 问多少次后重复, 设循环节为k
  第一次重复的数字肯定是最开始的a, 细节再问我
  (a+b*k)%c=a%c+b*k%c=a
  于是b*k%c=0, b*k是c的最小倍数
  k=b和c的最小公倍数除以b
  由于b=6789和c=1000000互质, 所以最小公倍数为b*c, k=b*c/b=c
  结论出来了:
  任选两个互质的b和c, 循环节都是c
*/