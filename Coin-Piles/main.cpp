#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)
#define rep(i,n) for(int i=0;i<n;++i)
#define per(i,n) for(int i=n-1;i>=0;--i)
#define ln "\n"
int MOD=1000000007;

void solve() {
  ll n, a, b; cin >> n;
  ll x, y;
  rep(_, n) {
    cin >> a >> b;
    if (a < b) swap(a, b);
    // x = y + (a - b)
    // replace in 2y + (a - b) = b
    // 2y = 2b - a // y = (2b - a) / 2
    y = (2 * b - a) / 3;
    x = y + (a - b);

    if (y < 0 || x < 0) { cout << "NO" << ln; continue; } 

    if (2 * x + y == a && 2 * y + x == b) {
      cout << "YES" << ln;
    } else cout << "NO" << ln;

    // cout << 2 * x + y << " " << 2 * y + x << ln;

  }
}

int main() {
  flash;
  solve();
  return 0;
}