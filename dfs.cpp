/*
const int M = 8, N = 4;
const double D = 1.5;
int a[M] = {2, 1, 5, 4, 15, 13, 11, 12, 14, 8, 4, 6, 3};
求包含a[0]的a[]的大小为N子集, 子集里两两的差大于D, 求所有这样的子集
MNDa都是变量

复杂度是O(M+XN)
m是输入， xn是输出

没有渐进更优， 只能常数优化

输入的复杂度加输出的复杂度

先排序和去重
r[i]表示右边哪些数跟a[i]相差大于D
然后跑个dfs, 剪枝是如果选了i往右边找不到g个数相差大于D， 那么再往右也找不到
r数组和剪枝的效果是只处理那些答案， 没有无效计算

复杂度是渐进最优的
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
	m = unique(a, a+M)-a;//去重，返回个数
	initr();
	dfs(0, 1);
	return 0;
}
