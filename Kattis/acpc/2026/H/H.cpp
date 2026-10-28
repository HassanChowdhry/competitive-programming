#include <bits/stdc++.h>
using namespace std;

char grid[6][6];
int con[6][6]['Z'];
char dc[] = {'L', 'R', 'U', 'D'};
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int n, m, r, c;
char d;
vector<vector<int>> rows(6, vector<int>(6));
vector<vector<int>> cols(6, vector<int>(6));

long long check() {
  int ok = 1;
  // for (int i = 1; i <= n; ++i) {
  //   for (int j = 1; j <= n; ++j) {
  //     cout << grid[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
  // cout << "\n\n";
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      // cout << grid[i][j] << "\n";
      if (grid[i][j] == '.') return 0LL;

      for (int d = 0; d < 4; ++d) {
        int ni = i + dx[d];
        int nj = j + dy[d];
        char move = dc[d];
        
        if (ni <= 0 || nj <= 0 || ni > n || nj > n || !con[i][j][move]) continue;
        if (grid[ni][nj] == '.') return 0LL;
        int x = grid[i][j] - '0';
        int y = grid[ni][nj] - '0';
        if (x > y) return 0LL;
      }
    }
  }
  
  // cout << "meow" << "\n";
  return 1LL;
}
long long rec(int r, int c) {
  long long ways = 0;

  if (r == n+1 && c == 1) {
    // return 1;
    return check();
  }

  if (grid[r][c] >= '1' && grid[r][c] <= '5') {
    if (c == n) return rec(r + 1, 1);
    else return rec(r, c + 1);
  }

  // UNDO ROWS, COLS

  for (int i = 1; i <= n; ++i) {
    if (!rows[r][i] && !cols[c][i]) {
      grid[r][c] = '0' + i;
      rows[r][i] = 1; cols[c][i] = 1;
      
      if (c == n) ways += rec(r + 1, 1);
      else ways += rec(r, c + 1);
      
      rows[r][i] = 0; cols[c][i] = 0;
      grid[r][c] = '.';
    }
  }

  return ways;
}

void solve() {
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> grid[i][j];
      if (grid[i][j] >= '1' && grid[i][j] <= '5') {
        int k = grid[i][j] - '0';
        rows[i][k] = 1;
        cols[j][k] = 1;
      }
    }
  }

  cin >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> r >> c >> d;
    con[r][c][d] = 1;
  }

  long long res = rec(1, 1);

  cout << res;
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  solve();
  return 0;
}