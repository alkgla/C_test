#include <iostream>
using namespace std;
void MatriaChain(int *p,int n,int **m,int **s);
//p为矩阵的行列集合，n个矩阵连乘，m存放乘法次数,s记录问题解决
int main(){
		

}
void MatriaChain(int *p,int n,int **m,int **s){
	int i;
	for(i=1;i<n;i++)  m[i][i]=0;
	for(int r=2;r<=n;r++)
		for(i=1;i<=n-r+1;i++){
			int j=i+r-1;
			m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];
			s[i][j]=i;
			for(int k=i+1;k<j;k++){
				int t=m[i][k]+m[k+1][[j]+p[i-1]*p[k]*p[j];
				if(t<m[i][j]){
					m[i][j]=t;
					s[i][j]=k;
				}
			}
		}
}