#include <iostream>
using namespace std;

/*          最长公共子序列 dp          */
int len(char *a);
void LCSLength(int m,int n,char *x,char *y);
int main(){
	char x[100]={0};
	char y[100]={0};
	
	cout<<"输入序列1：";
	char *p=x;
	cin>>p;
	
	cout<<"输入序列2：";
	char *q=y;
	cin>>q;
	
	int len_x=len(x);
	int len_y=len(y);
	
	LCSLength(len_x,len_y,x,y);
	
	
}
int len(char *a){
	int i=0;
	while(a[i++]!='\0');
	return i-1;
}
void LCSLength(int m,int n,char *x,char *y){
	//初始化阶段
	int **b=new int *[m+1];
	int **c=new int *[m+1];
	int i=0,j=0;
	for(i=0;i<=m;i++)
	{	
		b[i]=new int [n+1];
		c[i]=new int [n+1];
	}
	
	//初始化二维数组c
	for(i=0;i<=m;i++)  c[i][0]=0;
	for(i=0;i<=n;i++)  c[0][i]=0;

	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++){
			if(x[i-1]==y[j-1]){
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]=1;
			}else if(c[i-1][j]>=c[i][j-1]){
				c[i][j]=c[i-1][j];
				b[i][j]=2;
			}else{
				c[i][j]=c[i][j-1];
				b[i][j]=3;
			}
		}
		cout<<c[m][n]<<endl;
		
}