#include <bits/stdc++.h>
using namespace std;

// so we have a problem here
// 8x8 chessboard each square has a robot
// what is the expected number of empty squares
// after k moves.

// lets break this down, expected empty squares = SUM of probability of a square being empty
// E = SUM P(s_E)
// P(s_E) = ?
// for a robot the probability of it NOT being in square s at move k
// 1 - P(s,r,k) for 64 robots
// P(s_E) = MULT (1 - P(s, r, k))

// NOW transition for each P(s, r, k + 1) = SUM P(s_N, r, k) / deg(s_N)

const int R = 64, N = 8;
set<pair<int, int>> squares, squares_2;
double deg[9][9];
double B[9][9][101], B2[9][9][101];
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, -1, 1};
int k; 

void reset() {
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      for (int t = 0; t <= k; ++t) 
        B2[i][j][t] = 0.0;
    }
  }

  squares.clear();
  squares_2.clear();
}

void push() {
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      if (B[i][j][k] == 0) {
        B[i][j][k] = (1.0 - B2[i][j][k]);
        continue;
      }

      B[i][j][k] = B[i][j][k] * (1.0 - B2[i][j][k]);
    }
  }
}

void solve() {
  cin >> k;

  deg[1][1] = deg[1][8] = deg[8][1] = deg[8][8] = 2.0;

  for (int i = 2; i < N; ++i) {
    deg[i][1] = deg[1][i] = deg[i][N] = deg[N][i] = 3.0;

    for (int j = 2; j < N; ++j) {
      deg[i][j] = 4.0;
    }
  }

  // for (int i = 1; i <= N; ++i) {
  //   for (int j = 1; j <= N; ++j) {
  //     cout << deg[i][j] << " ";
  //   }
  //   cout << "\n";
  // }

  // for (int i = 1; i <= N; ++i) {
  //   for (int j = 1; j <= N; ++j) {
  //     for (int t = 0; t <= k; ++t)
  //       B[i][j][t] = 1.0;
  //   }
  // }

  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      reset();
      squares.insert({i, j});
      B2[i][j][0] = 1.0;

      for (int t = 0; t < k; ++t) {
        for (pair<int, int> p : squares) {
          auto [r, c] = p;
          
          for (int d = 0; d < 4; ++d) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (!(nr >= 1 && nr <= 8 && nc >= 1 && nc <= 8)) continue;
            
            squares_2.insert({nr, nc});
            B2[nr][nc][t + 1] += B2[r][c][t] / deg[r][c];
          }
        }

        squares = squares_2;
        squares_2.clear();
      } 

      push();
    }
  }

  double ans = 0;

  // for (int i = 1; i <= N; ++i) {
  //   for (int j = 1; j <= N; ++j) {
  //     cout << B[i][j][k] << " ";
  //   }
  //   cout << "\n";
  // }
  // cout << "\n\n";
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      ans += B[i][j][k];
    }
  }

  cout << fixed << setprecision(6) << ans;
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  // int t; cin >> t;
  // while(t--)
  solve();
  return 0;
}