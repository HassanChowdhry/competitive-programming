#include <bits/stdc++.h>
using namespace std;

string reconstruct_path(vector<vector<pair<int, int>>>& parent, int si, int sj, int i, int j) {
  string path;
  while (i != si || j != sj) {
    int pi = parent[i][j].first; int pj = parent[i][j].second;

    if (i == pi + 1) { path += 'D'; }
    else if (i == pi - 1) { path += 'U'; }
    else if (j == pj + 1) { path += 'R'; }
    else if (j == pj - 1) { path += 'L'; }

    i = pi; j = pj;
  }

  reverse(path.begin(), path.end());
  return path;
}

string bfs(int si, int sj, int x, int y, vector<vector<char>>& arr) {
  vector<vector<pair<int, int>>> parent(x, vector<pair<int, int>>(y, {-1, -1}));
  vector<vector<bool>> visited(x, vector<bool>(y, false));
  queue<pair<int, int>> q; q.push({si, sj}); visited[si][sj] = true;

  int dr[] = {-1, 1, 0, 0}; int dc[] = {0, 0, -1, 1};

  while (!q.empty()) {
    int r = q.front().first; int c = q.front().second; q.pop();

    if (arr[r][c] == 'B') 
      { return reconstruct_path(parent, si, sj, r, c); }

    for (int k = 0; k < 4; ++k) {
      int nr = r + dr[k];
      int nc = c + dc[k];
      if (nr >= 0 && nr < x && nc >= 0 && nc < y && !visited[nr][nc] && arr[nr][nc] != '#') 
        { visited[nr][nc] = true; parent[nr][nc] = {r, c}; q.push({nr, nc}); }
    }
  }
  return "";
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<char>> input(n, vector<char>(m));

  int start_i = -1, start_j = -1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> input[i][j];
      if (input[i][j] == 'A') 
        { start_i = i; start_j = j; }
    }
  }

  if (start_i == -1 || start_j == -1) 
    { cout << "NO"; return 0; }

  string res = bfs(start_i, start_j, n, m, input);
  
  if (res.empty()) 
    { cout << "NO"; } 
  else 
    { cout << "YES\n" << res.length() << "\n" << res; }
  return 0;
}
