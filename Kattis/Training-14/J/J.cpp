#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define ii pair<int, int>

const int maxN = 15;
int n;
vector<double> slopes;
double dp[1 << maxN][maxN];
ii points[maxN];

// y = mx + b -> b = y - mx
double dist(ii pa, ii pb, double m) {
  if (m == 0) {
    return abs((double)pb.x - pa.x) + abs((double)pb.y - pa.y);
  }

  double invm = -1.0 / m;

  double b1 = pa.y - m * pa.x;
  double b2 = pa.y - invm * pa.x;

  double d1 = abs(m * pb.x - pb.y + b1) / sqrt(m * m + 1);
  double d2 = abs(invm * pb.x - pb.y + b2) / sqrt(invm * invm + 1);

  return d1 + d2;
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> points[i].x >> points[i].y;
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      if (points[j].x - points[i].x == 0) {
        slopes.push_back(0);
        continue;
      }
      double slope = (double)(points[j].y - points[i].y) / (double)(points[j].x - points[i].x);
      slopes.push_back(slope);
    }
  }

  double ans = DBL_MAX;
  for (double slope : slopes) {
    for (int mask = 0; mask < (1 << n); ++mask) {
      for (int i = 0; i <= n; ++i) {
        dp[mask][i] = DBL_MAX;
      }
    }
  
    for (int mask = 0; mask < (1 << n); ++mask) {
      if (__builtin_popcount(mask) == 1) {
        for (int i = 1; i <= n; ++i) {
          if (mask & (1 << (i - 1))) {
            dp[mask][i] = 0;
          }
        }
      }
    }
    dp[0][0] = 0;

    // cout << "SLOPE: " << slope << "\n";
    for (int mask = 1; mask < (1 << n); ++mask) {
      if (__builtin_popcount(mask) == 1) continue;
      // where can I come from starting i 
      for (int i = 1; i <= n; ++i) {
        if ((mask & 1 << (i - 1)) == 0) continue;
        int oldMask = mask ^ (1 << (i - 1));
        for (int j = 1; j <= n; ++j) {
          if (i == j || (mask & 1 << (j - 1)) == 0) continue;
          // cout << mask << " " << i << " " << dp[mask][i] << "\n";
          // cout << dist(points[i], points[j], slope) << "\n";
          dp[mask][i] = min(dp[mask][i], dp[oldMask][j] + dist(points[i], points[j], slope));
          // cout << oldMask << " " << j << " " << dp[oldMask][j] << "\n\n";
        }
      }
    }

    for (int i = 1; i <= n; ++i) {
      ans = min(ans, dp[(1 << n)-1][i]);
    }
  }
  
  cout << fixed << setprecision(7) << ans;
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  solve();
  return 0;
}