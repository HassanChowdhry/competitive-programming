#include <bits/stdc++.h>
using namespace std;

const int N = 8;
const int h[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int v[] = {1, 2, 2, 1, -1, -2, -2, -1};

int ans[N+1][N+1], vis[N+1][N+1], deg[N+1][N+1];

struct state {
    int deg, x, y;

    bool operator<(const state& other) const {
          if (deg != other.deg) return deg < other.deg;
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
};


bool in(int x, int y) {
  return 1 <= x && x <= N && 1 <= y && y <= N; 
}

void mark(int id, int x, int y) {
  ans[x][y] = id;
  vis[x][y] = 1;

  for (int i = 0; i < N; ++i) {
    int dx = x + h[i];
    int dy = y + v[i];

    if (in(dx, dy) && !vis[dx][dy]) {
      --deg[dx][dy];
    }
  }
}

void unmark(int id, int x, int y) {
  ans[x][y] = -1;
  vis[x][y] = 0;

  for (int i = 0; i < N; ++i) {
    int dx = x + h[i];
    int dy = y + v[i];

    if (in(dx, dy) && !vis[dx][dy]) {
      ++deg[dx][dy];
    }
  }
}

bool dfs(int id, int x, int y) {
  mark(id, x, y);
  vector<state> moves;
  if (id >= 64) return true;

  for (int i = 0; i < N; ++i) {
    int dx = x + h[i];
    int dy = y + v[i];

    if (in(dx, dy) && !vis[dx][dy]) {
      moves.push_back({ deg[dx][dy], dx, dy });
    }
  }

  sort(moves.begin(), moves.end());

  for (state T: moves) {
    if (dfs(id + 1, T.x, T.y)) return true;
  }
  unmark(id, x, y);
  return false;
}

void solve() {
  int m, n;
  cin >> m >> n;

  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      for (int d = 0; d < N; ++d) {
        int dx = i + h[d];
        int dy = j + v[d];

        if (in(dx, dy)) ++deg[i][j];
      }
    }
  }

  dfs(1, n, m);

  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      cout << ans[i][j] << " ";
    } cout << "\n";
  }

}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  solve();
  return 0;
}