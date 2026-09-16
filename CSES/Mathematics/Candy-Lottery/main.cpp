#include <bits/stdc++.h>
using namespace std;
int n, k;
double a, b, res;

// we need to split the numerator and denom
// to or do we ? 
// its probability?? so the number will naturally be small

void solve() {
  cin >> n >> k;
  // P(Xmax=x) * x
  // P(Xmax=x) = P(X=x) ^ n - P(X=x-1) ^ n
  // P(X=x) is the probablity of the number being
  // at most x.


  for (int i = 1; i <= k; ++i) {
    a = 1.0; b = 1.0;
    
    for (int _ = 1; _ <= n; ++_) {
      a *= (double) i / k;
      b *= (double) (i - 1) / k;
    }
    res += i * (a - b);
  }
  
  // cout << fixed << setprecision(7) << res << "\n";
  printf("%.6f\n", res);
}
int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  // int t; cin >> t;
  // while(t--)
  solve();
  return 0;
}