#include <bits/stdc++.h>
using namespace std;


int n, q, s, e, T, ans;
const int lg = 20, maxT = 1e6 + 1;
int up[maxT][lg];
int m[maxT];

void solve() {
  cin >> n >> q;
  fill(m, m + maxT, maxT);
  T = 0;
  
  for (int i = 1; i <= n; ++i) {
    cin >> s >> e;

    m[s] = min(m[s], e);
    T = max(T, e);
  }

  e = maxT;
  
  for (int t = maxT-1; t >= 0; --t) {
    e = min(e, m[t]);
    up[t][0] = e;
  }
  
  // for (int t = 0; t < maxT; ++t) {
  //   cout << "START : " << t << " END: " << up[t][0] << "\n";
  // }
  
  
  for (int p = 1; p < lg; ++p) {
    for (int t = 0; t < maxT; ++t) {
      if (up[t][p-1] >= maxT) up[t][p] = maxT;
      else up[t][p] = up[ up[t][p-1] ][p-1];
    }
  }
  // cout << "START : " << 7 << " END: " << up[7][0] << " END_2: " << up[7][1] << " END_3: " << up[7][2] << " END_4: " << up[7][3] << "\n";
  // cout << "START : " << 10 << " END: " << up[10][0] << " END: " << up[10][1] <<  "\n";

  while (q--) {
    cin >> s >> e;
    ans = 0;
    // cout << "START Q: " << s << " END Q: " << e << "\n";
    for (int p = lg-1; p >= 0; --p) {
      int n_e = up[s][p];
      // cout << n_e << "\n";
      if (!n_e || n_e > e) continue;;
      s = up[s][p];
      ans += (1 << p);
    }

    cout << ans << "\n";
  }
  
  // int a, b, k;
  // rep(_, q) {
  //   cin >> a >> b;
  //   if (depth[a] > depth[b]) swap(a, b);
  //   k = depth[b] - depth[a];
  //   rep(i, LOG) {
  //     if (k & ( 1 << i )) b = dp[b][i];
  //   }
  //   if (a == b) { cout << a << ln; continue; }

  //   for (int log = 20; log >= 0; --log) {
  //     if (log >= depth[a]) continue;
  //     if (dp[a][log] != dp[b][log])
  //       { a = dp[a][log]; b = dp[b][log]; }
  //   }
  //   cout << dp[a][0] << ln;
  // }
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  solve();
  return 0;
}