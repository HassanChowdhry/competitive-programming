#include <bits/stdc++.h>
#define MOD 1000000007
#define inf 1000000009
using namespace std;

int dfs(int i, int j, int n, int m, vector<vector<char>>& input) {
  if (i < 0 || i >= n || j < 0 || j >= m || input[i][j] == '#')
    { return inf; }
  if (input[i][j] == 'B') 
    { return 0; }
  
  input[i][j] = '#';

  int u = dfs(i+1, j, n, m, input);
  int d = dfs(i-1, j, n, m, input);
  int r = dfs(i, j+1, n, m, input);
  int l = dfs(i, j-1, n, m, input);

  return 1 + min(min(l, r), min(u, d));
}

int main() {
  int n, m, res = 0;
  cin >> n >> m;

  vector<vector<char>> input(n, vector<char>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> input[i][j];
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (input[i][j] == 'A') 
        { res = dfs(i, j, n, m, input); }
    }
  }
  
  string out = (res == inf ? "NO" : "YES");
  cout << out << "\n" << res;
}