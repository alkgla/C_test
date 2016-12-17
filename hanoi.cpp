#include <iostream>
//汉诺塔递归求法
using namespace std;
void hanoi(int n,char start,int temp,char end);
int main(){
	hanoi(3,'S','T','E');
}
void hanoi(int n,char start,int temp,char end){
	if(n<=1)
		cout<<"将"<<start<<"移到"<<end<<endl;
	else{
		hanoi(n-1,start,end,temp);
		cout<<"将"<<start<<"移到"<<end<<endl;
		hanoi(n-1,temp,start,end);
	}
}