#include <bits/stdc++.h>
using namespace std;

char grid[22][22];
void solve() {
  int n, m; cin >> n >> m;

  for (int i = 0; i <= 21; ++i) {
    for (int j = 0; j <= 21; ++j) grid[i][j] = 'W';
  }

  string line;
  for (int i = 1; i <= n; ++i) {
    cin >> line;
    int j = 1;
    for (char c : line) {
      grid[i][j] = c;
      ++j;
    }
  }

  vector<pair<int, int>> ans(3);

  char color;
  int ni, nj;
  for (int curr = 1; curr <= 3; ++curr) {
    if (curr == 1) color = 'R';
    if (curr == 2) color = 'G';
    if (curr == 3) color = 'B';

    pair<int, int> LF = {0, 0}, LM = {0, 0}, M = {0, 0};
    vector<vector<int>> prev(22, vector<int>(22));

    vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int i = 1; i <= 20; ++i) {
      for (int j = 1; j <= 20; ++j) {
        if (grid[i][j] != color) continue;
        int cnt = 0;
        for (int d = 0; d < 8; ++d) {
          ni = i + dx[d];
          nj = j + dy[d];
          if (grid[ni][nj] == color) {
            ++cnt;
          }
        }

        if (cnt == 2) {
          if (LF.first == 0 && LF.second == 0) {
            LF = {i, j};
          }
        }
        
        if (cnt == 1) {
          if (LF.first == 0 && LF.second == 0) {
            LF = {i, j};
          } 
          
          if(LM.first == 0 && LM.second == 0) {
            LM = {i, j};
          }
          
          M = {i, j}; 
        }
      }
    }

    cout << LF.first << " " << LF.second << " ";
    cout << LM.first << " " << LM.second << " ";
    cout << M.first << " " << M.second << "\n";
    // cout << " ( " << LF.first << " " << LF.second << " ) \n";
    // cout << " ( " << LM.first << " " << LM.second << " ) \n";
    // cout << " ( " << M.first << " " << M.second << " ) \n\n";
  }
  
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  solve();
  return 0;
}