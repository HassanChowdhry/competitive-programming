#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int n, m;
char b[9][9];
char p, r, c;
vector<string> ans;

int clear(pair<int, int> from, pair<int, int> to, char direction) {
  if (direction == 'S') {
    if (from.x == to.x) {
      int l = min(to.y, from.y), r = max(to.y, from.y);
      for (int j = l + 1; j < r; ++j) {
        if (b[from.x][j] != '.') return 0;
      }
    }
    if (from.y == to.y) {
      int l = min(to.x, from.x), r = max(to.x, from.x);
      for (int j = l + 1; j < r; ++j) {
        if (b[from.y][j] != '.') return 0;
      }
    }
  }

  if (direction == 'D') {
    if (from.x == from.y && to.x == to.y) {
      int l = min(from.x, to.y), r = max(from.x, to.y);
      for (int j = l + 1; j < r; ++j) {
        if (b[j][j] != '.') return 0;
      }
    } else {
      int i = min(to.x, from.x), j = max(to.y, from.y);
      int ei = max(to.x, from.x), ej = min(to.y, from.y);
      for (int r = i + 1, c = j - 1; r < ei && c < ej; --r, --c) {
        if (b[r][c] != '.') return 0;
      }
    }
  }

  return 1;
}

int move(char piece, pair<int, int> from, pair<int, int> to) {

  // cout << piece << ": (" << from.x << ", " << from.y << ") to : " " (" << to.x << ", " << to.y << ")" << "\n";
  if (piece == 'Q') {
    return (abs(to.y - from.y) == abs(to.x - from.x) && clear(from, to, 'D')) || ((abs(to.x - from.x) == 0 || abs(to.y - from.y) == 0) && clear(from, to, 'S'));
  } else if (piece == 'B') {
    return  (abs(to.y - from.y) == abs(to.x - from.x) && clear(from, to, 'D'));
  } else if (piece == 'R') {
    return ((abs(to.x - from.x) == 0 || abs(to.y - from.y) == 0) && clear(from, to, 'S'));
  } else if (piece == 'N') {
    return (abs(to.y - from.y) == 1 && abs(to.x - from.x) == 2) || (abs(to.y - from.y) == 2 && abs(to.x - from.x) == 1);
  } else if (piece == 'K') {
    return abs(to.y - from.y) <= 1 && abs(to.x - from.x) <= 1;
  }
  return 0;
}

int check() {
  int ok = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      
      if (b[i][j] != '.' && ok) return 0;
      if (b[i][j] != '.') ok = 1;
      
    }
  }
  return ok;
}

int rec(int moves) {
  if (moves < 0) { return 0; }
  if (moves == 0) { return check(); }

  int ok = 0;
  for (int i = n; i >= 1; --i) {
    for (int j = 1; j <= n; ++j) {
      if (b[i][j] != '.') {
        // int ok = 0;
        for (int r = n; r >= 1; --r) {
          for (int c = 1; c <= n; ++c) {
            if (b[r][c] == '.') continue;
            if (r != i || j != c) {
              if (move(b[i][j], {i, j}, {r, c})) {
                // cout << " YESS\n";
                // cout << b[i][j] << " " << i << " " << j << " " << moves << "\n";
                char temp = b[r][c];
                b[r][c] = b[i][j];
                b[i][j] = '.';
                ok = rec(moves - 1);
                b[i][j] = b[r][c];
                b[r][c] = temp;
                if (ok) {
                  char c1 = (n-i+'A');
                  char c2 = (n-r+'A');
                  string s = "";
                  s += b[i][j]; s += ": "; s += c1; s += to_string(j); s += " -> "; s += c2; s += to_string(c);
                  ans.push_back(s);
                  // cout << b[i][j] << " " << c1 << j << " " << c2 << c << "\n";
                  return ok;
                }
              }
            }
          }
        }
      }
    }
  }

  // if (ok && moves == m) {
  //   cout << ok << "\n";
  // }

  return ok;
}

void solve() {
  cin >> n >> m;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      b[i][j] = '.';
    }
  }

  for (int i = 1; i <= m; ++i) {
    cin >> p >> r >> c;
    b[n-r+'A'][c-'0'] = p;
  }
  // for (int i = 1; i <= n; ++i) {
  //   for (int j = 1; j <= n; ++j) {
  //     cout << b[i][j] << "\t";
  //   }cout << "\n";
  // }

  int ok = rec(m-1);
  if (ok) {
    for (int i = ans.size()-1; i >= 0; --i) {
      cout << ans[i] <<"\n";
    }
  } else {
    cout << "No Solution";
  }

  // cout << ok << "\n";
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  solve();
  return 0;
}