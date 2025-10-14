#include <bits/stdc++.h>
using namespace std;

char grid[105][105];
void solve() {
  int m, n; cin >> n >> m;
  for (int i =1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> grid[i][j];
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int ok1 = 0;
      int ok2 = 0;

      if (grid[i][j] == '*') continue;

      for (int z = i+1; z <= n; ++z) if (grid[z][j] == '*') ok1 = 1;
      for (int z = i-1; z > 0; --z) if (grid[z][j] == '*') ok1 = 1;
      
      for (int z = j+1; z <= m; ++z) if (grid[i][z] == '*') ok2 = 1;
      for (int z = j-1; z > 0; --z) if (grid[i][z] == '*') ok2 = 1;

      if (ok1 && ok2) {
        cout << i << " " << j; return;
      }
      
    }
  }
}

int main() {
  solve();
  return 0;
}