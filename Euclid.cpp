//辗转相除法的基本原理是：两个数的最大公约数等于它们中较小的数和两数之差的最大公约数。

#include<iostream>  
using namespace std;  
int gcd(int x,int y)//辗转相除法求最大公约数  
{  
    int s;  
    while((s=(x%y))!=0)  
    {  
        x=y;  
        y=s;  
    }
    return y;  
}
int main()
{
    int x,y,a,b;
    cin>>x>>y;
	a=gcd(x,y); //求最大公约数
    b=x*y/a;    //求最小公倍数
	
	cout<<"最大公约数为"<<a<<endl;
    cout<<"最小公倍数为"<<b<<endl;
	
    return 0;
}