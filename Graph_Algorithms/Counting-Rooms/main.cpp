#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

void dfs(int i, int j, int n, int m, vector<vector<char>>& input) {
  if (i < 0 || i >= n || j < 0 || j >= m || input[i][j] != '.')
    { return; }
  
  input[i][j] = '#';
  dfs(i+1, j, n, m, input);
  dfs(i-1, j, n, m, input);
  dfs(i, j+1, n, m, input);
  dfs(i, j-1, n, m, input);
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
      if (input[i][j] == '.') 
        { dfs(i, j, n, m, input); ++res; }
    }
  }
  
  cout << res;
}