//��һ������a=1234, ÿ������6789�����������1000000�ͼ�ȥ1000000, �����Ӷ��ٴκ�����ظ���a
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
  ��������һ��, ����aÿ�μ�b����cȡ����, �ʶ��ٴκ��ظ�, ��ѭ����Ϊk
  ��һ���ظ������ֿ϶����ʼ��a, ϸ��������
  (a+b*k)%c=a%c+b*k%c=a
  ����b*k%c=0, b*k��c����С����
  k=b��c����С����������b
  ����b=6789��c=1000000����, ������С������Ϊb*c, k=b*c/b=c
  ���۳�����:
  ��ѡ�������ʵ�b��c, ѭ���ڶ���c
*/