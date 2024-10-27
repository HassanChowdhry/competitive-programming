#include <bits/stdc++.h>
#define MOD 1000000007
#define inf 1000000009
using namespace std;

int bfs(int i, int j, int n, int m, vector<vector<char>>& input) {

}

int main() {
  int n, m, res = 0;
  cin >> n >> m;
  vector<vector<char>> input(n, vector<char>(m));
  string path = "";

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> input[i][j];
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (input[i][j] == 'A') continue;
        // { res = dfs(i, j, n, m, input); }
    }
  }

  reverse(path.begin(), path.end());
  path = path.substr(0, res);
  
  if (res >= inf)
    { cout << "NO"; return 0; }

  cout << "YES" << "\n" << res << "\n" << path;
}