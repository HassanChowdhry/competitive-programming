#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ump unordered_map
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ln "\n"

int dirx[] = {-1, -1, -1, 1, 1, 1, 0, 0};
int diry[] = {-1, 0, 1, -1, 0, 1, -1, 1};

char grid[105][105];
// int dp[105][105][105];
unordered_map<ll, int> dp; // compressed 3D DP
vector<vector<int>> coord;
string s;
int n, m, sn;

inline ll key(int i, int j, int d) {
  return ((ll)i << 20) | ((ll)j << 10) | d;
}

int dfs(int i, int j, int d) {
  ll k = key(i, j, d);
  if (dp.count(k)) return dp[k];
  if (d == sn-1) {
    coord.pb({i, j});
    return dp[k] = 1;
  }

  int curr = 0;
  for (int z = 0; z < 8; ++z) {
    int r = i + dirx[z];
    int c = j + diry[z];

    if (r > 0 && c > 0 && r <= n && c <= m && s[d + 1] == grid[r][c]) {
      int check = dfs(r, c, d + 1);
      curr += check;
      if (curr > 1) return curr;
    }
  }

  if (curr == 1) coord.pb({i, j});
  return dp[k]=curr;
}

void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> grid[i][j];
    }
  }
  cin >> s;
  sn = s.size();

  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (grid[i][j] == s[0]) {
        cnt += dfs(i, j, 0);
        if (cnt > 1) {
          cout << "Fake map!"; return;
        }
      }
    }
  }

  if (cnt == 0) { cout << "Not found"; return; }
  reverse(coord.begin(), coord.end());
  for (vector<int> cord: coord) {
    cout << "(" << cord[0] << "," << cord[1] << ")" << ln;
  }

}

int main() {
  flash;
  solve();
  return 0;
}