/*
const int M = 8, N = 4;
const double D = 1.5;
int a[M] = {2, 1, 5, 4, 15, 13, 11, 12, 14, 8, 4, 6, 3};
�����a[0]��a[]�Ĵ�СΪN�Ӽ�, �Ӽ��������Ĳ����D, �������������Ӽ�
MNDa���Ǳ���

���Ӷ���O(M+XN)
m�����룬 xn�����

û�н������ţ� ֻ�ܳ����Ż�

����ĸ��Ӷȼ�����ĸ��Ӷ�

�������ȥ��
r[i]��ʾ�ұ���Щ����a[i]������D
Ȼ���ܸ�dfs, ��֦�����ѡ��i���ұ��Ҳ���g����������D�� ��ô������Ҳ�Ҳ���
r����ͼ�֦��Ч����ֻ������Щ�𰸣� û����Ч����

���Ӷ��ǽ������ŵ�
*/

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int M = 13, N = 4;
const double D = 1.5;

int m, r[M], b[N], a[M] = {2, 1, 5, 4, 15, 13, 11, 12, 14, 8, 4, 6, 3};

void initr() {
	for(int i = 0, j = 1; i < m; ++i) {
		while(j<m && a[j]-a[i]<=D) ++j;
		r[i] = j;
	}
}

bool dfs(int dep, int i) {
	b[dep] = i;
	if(dep == N-1) {
		for(int k = 0; k < N; ++k) printf("%d ", a[b[k]]);
		puts("");
		return true;
	}
	bool ans = false;
	for(int j = r[i]; j < m; ++j) {
		if(dfs(dep+1, j)) ans = true;
		else /*        */ return ans;
	}
	return ans;
}

int main() {
	sort(a, a+M);
	m = unique(a, a+M)-a;//ȥ�أ����ظ���
	initr();
	dfs(0, 1);
	return 0;
}
