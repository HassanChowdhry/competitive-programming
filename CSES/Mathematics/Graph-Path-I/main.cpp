#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int oo = 1e9 + 7;
int n, m;
ll k;
int u, v;

const int maxN = 101;
ll V[maxN][maxN];
ll V0[maxN][maxN];
ll C[maxN][maxN];

void matmul(ll A[maxN][maxN], ll B[maxN][maxN]) {

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      C[i][j] = 0;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      for(int z = 0; z < n; z++){
        C[i][j] += A[i][z] * B[z][j];
        C[i][j] %= oo;
      }
    }
  }

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      A[i][j] = C[i][j];
}

void solve() {
  cin >> n >> m >> k;
  
  for (int i = 0; i < m; ++i) {
    cin >> u >> v;
    --u;--v;
    ++V[u][v];
  }

  for (int i = 0; i < n; ++i) V0[i][i] = 1;

  while (k){
    if (k & 1) {
      matmul(V0, V);
    }

    matmul(V, V);
    k >>= 1;
  }

  // V^k is the answer for exactly k edges
  cout << V0[0][n-1];
  // for (int i = 0; i < n; ++i) {
  //   for (int j = 0; j < n; ++j) {
  //     cout << V0[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
  
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  // int t; cin >> t;
  // while(t--)
  solve();
  return 0;
}