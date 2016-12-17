#include<iostream>
using namespace std;
#define DEL_H(c) L[R[c]] = L[c], R[L[c]] = R[c]
#define INS_H(c) L[R[c]] =   c , R[L[c]] =   c 
#define DEL_V(x) U[D[x]] = U[x], D[U[x]] = D[x]
#define INS_V(x) U[D[x]] =   x , D[U[x]] =   x 
#define RST(a, v) memset(a, v, sizeof a)
// 13C
#define  forl(i, a, b) for(int i = (a); i <  (b); ++i)
#define forle(i, a, b) for(int i = (a); i <= (b); ++i)
#define  forg(i, b, a) for(int i = (b); i >  (a); --i)
#define forge(i, b, a) for(int i = (b); i >= (a); --i)
#define rep(n) for(int repp = 0; repp < (n); ++repp)

const int N = 9;
const int M = N*N*N*4 + N*N*4 + 2;
const int ROW = N*N*N + 2;
const int COL = N*N*4 + 2;

int sz;
int U[M], D[M], L[M], R[M], C[M], X[M];
int H[ROW];
int S[COL], Q[COL], vis[COL];
int ans[N][N];
char a[COL];

void init_lists(int r, int c) {
  forle(j, 0, c) {
    S[j] = 0;
    U[j] = D[j] = j;
    L[j+1] = j;
    R[j] = j+1;
  }
  R[c] = 0;
  sz = c;
  RST(H, 0);
}

void place(int i, int j, int k, int &r, int &c1, int &c2, int &c3, int &c4) {
  r  = (i*N+j)*N+k;
  c1 = i*N+j+1;
  c2 = N*N*1 + i*N+k;
  c3 = N*N*2 + j*N+k;
  c4 = N*N*3 + (i/3*3+j/3)*N+k;
}

void link(int r, int c) {
  ++S[c];
  ++sz;
  C[sz] = c;
  X[sz] = r;
  U[sz] = c;
  D[sz] = D[c];
  INS_V(sz);
  if(H[r] == 0)
    H[r] = L[sz] = R[sz] = sz;
  else {
    L[sz] = H[r];
    R[sz] = R[H[r]];
    INS_H(sz);
  }
}

void init_matrix() {
  bool vis[COL] = {false};
  int k = 0;
  int r, c1, c2, c3, c4;
  forl(i, 0, N)
    forl(j, 0, N) {
      if(a[k] != '.') {
        place(i, j, a[k]-'0', r, c1, c2, c3, c4);
        vis[c1] = vis[c2] = vis[c3] = vis[c4] = true;
        link(r, c1), link(r, c2), link(r, c3), link(r, c4);
      }
      ++k;
    }
  forl(i, 0, N)
    forl(j, 0, N)
      if(a[i*N+j] == '.')
        forle(l, 1, 9) {
          place(i, j, l, r, c1, c2, c3, c4);
          if(vis[c1] || vis[c2] || vis[c3] || vis[c4]) continue;
          link(r, c1), link(r, c2), link(r, c3), link(r, c4);
        }
}

void remov(int c) {
  DEL_H(c);
  for(int i = D[c]; i != c; i = D[i])
    for(int j = R[i]; j != i; j = R[j]) {
      DEL_V(j);
      --S[C[j]];
    }
}

void resume(int c) {
  for(int i = U[c]; i != c; i = U[i])
    for(int j = L[i]; j != i; j = L[j]) {
      INS_V(j);
      ++S[C[j]];
    }
  INS_H(c);
}

bool dfs(int dep) {
  if(R[0] == 0) {
    forl(i, 0, dep) {
      int x = (X[Q[i]]-1)/N/N;
      int y = (X[Q[i]]-1)/N%N;
      ans[x][y] = (X[Q[i]]-1)%N+1;
    }
    return true;
  }
  
  int mn = INT_MAX, c;
  for(int i = R[0]; i != 0; i = R[i])
    if(mn > S[i])
       mn = S[i], c = i;
  
  remov(c);
  for(int i = D[c]; i != c; i = D[i]) {
    Q[dep] = i;
    for(int j = R[i]; j != i; j = R[j]) remov(C[j]);
    if(dfs(dep+1)) return true;
    for(int j = L[i]; j != i; j = L[j]) resume(C[j]);
  }
  resume(c);
  return false;
}

void print() {
  forl(i, 0, N)
    forl(j, 0, N)
      printf("%d", ans[i][j]);
  puts("");
}

int main() {
  while(gets(a), a[0] != 'e') {
    init_lists(ROW-2, COL-2);
    init_matrix();
    dfs(0);
    print();
  }
  return 0;
}