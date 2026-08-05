#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll oo = 2e18;
int n, m;
ll k;
int u, v, w;

const int maxN = 101;
ll V[maxN][maxN];
ll V0[maxN][maxN];

// to get the min, we adjust the matmul formula
// to get min of A[i][k] + b[k][j]
void matmul(ll A[maxN][maxN], ll B[maxN][maxN]) {
  ll C[maxN][maxN];

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      C[i][j] = oo;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      for(int z = 0; z < n; z++){
        C[i][j] = min(C[i][j], A[i][z] + B[z][j]);
      }
    }
  }

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      A[i][j] = C[i][j];
}

void solve() {
  cin >> n >> m >> k;
  
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      V[i][j] = oo;
      V0[i][j] = oo;
    }
  }
  
  for (int i = 0; i < m; ++i) {
    cin >> u >> v >> w;
    --u;--v;
    V[u][v] = min(V[u][v], 1LL * w);
  }

  for (int i = 0; i < n; ++i) V0[i][i] = 0;

  while (k){
    if (k & 1) {
      matmul(V0, V);
    }

    matmul(V, V);
    k >>= 1;
  }

  // V^k is the answer for exactly k edges
  if (V0[0][n-1] == oo) cout << -1;
  else cout << V0[0][n-1];
  // for (int i = 0; i < n; ++i) {
  //   for (int j = 0; j < n; ++j) {
  //     if (V0[i][j] == oo) {
  //       cout << "-1" << " ";
  //     } else cout << V0[i][j] << " ";
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