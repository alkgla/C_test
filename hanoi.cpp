#include <iostream>
//��ŵ���ݹ���
using namespace std;
void hanoi(int n,char start,int temp,char end);
int main(){
	hanoi(3,'S','T','E');
}
void hanoi(int n,char start,int temp,char end){
	if(n<=1)
		cout<<"��"<<start<<"�Ƶ�"<<end<<endl;
	else{
		hanoi(n-1,start,end,temp);
		cout<<"��"<<start<<"�Ƶ�"<<end<<endl;
		hanoi(n-1,temp,start,end);
	}
}