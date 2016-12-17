/*新年快到了，“猪头帮协会”准备搞一个聚会，已经知道现有会员N人，把会员从1到N编号，
其中会长的号码是N号，凡是和会长是老朋友的，那么该会员的号码肯定和N有大于1的公约数，
否则都是新朋友，现在会长想知道究竟有几个新朋友？请你编程序帮会长计算出来。
Input
	第一行是测试数据的组数CN（Case number，1<CN<10000），接着有CN行正整数N（1<n<32768），表示会员人数。
 
Output
	对于每一个N，输出一行新朋友的人数，这样共有CN行输出。
	
Sample Input
	2
	25608
	24027
		  
Sample Output
	7680
	16016
  */		
//思路1：n以内所有的素数和								
//思路2：利用欧拉函数，有euler(n)=n*(1-1/p1)*(1-1/p2)*...(1-1/pn)
#include <iostream>
#include <math.h>
using namespace std;
int main(){
	int t,a;
	int p[32768];
	cout<<"请输入你要测试几组数据,再分别输入数据";
	cin>>t;
	while(t--){
		
		cin>>a;
		int i=1;
		while(++i<=a)
			p[i]=1;
		for(i=2;i<=a;i++)//被i整除或者i的n倍
        {
            if(a%i==0)
                for(int j=i;j<=a;j+=i)
                    p[j]=0;//所以是n的因子和有相同因子的都赋值为0，除掉
        }
		int sum=0;
		for(i=2;i<=a;++i)
			if(p[i]) 
				++sum;
		cout<<sum<<endl;
	}
}