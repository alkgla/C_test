//շת������Ļ���ԭ���ǣ������������Լ�����������н�С����������֮������Լ����

#include<iostream>  
using namespace std;  
int gcd(int x,int y)//շת����������Լ��  
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
	a=gcd(x,y); //�����Լ��
    b=x*y/a;    //����С������
	
	cout<<"���Լ��Ϊ"<<a<<endl;
    cout<<"��С������Ϊ"<<b<<endl;
	
    return 0;
}