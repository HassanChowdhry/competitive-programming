#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod(num, n) (num % n + n) % n
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)
#define rep(i,n) for(int i=0;i<n;++i)
#define repx(i,x,n) for(int i=x;i<n;++i)
#define input(arr,n);for(int i=0;i<n;++i)cin>>arr[i]
#define ln "\n"
ll MOD=1000000007;

// fermats little thoerem / eulers theorem
ll exp(ll a, ll b, ll n) {
  if (b == 0) return 1;
  if (b == 1) return a % (MOD-n);
  if (b == 2) return (a * a) % (MOD-n);
  
  if (b % 2) {
    return ((exp(a, b / 2, n) * exp(a, b / 2, n) % (MOD-n)) * a) % (MOD-n);
  }

  return (exp(a, b / 2, n) * exp(a, b / 2, n)) % (MOD-n);
}

void solve() {
  ll n, a, b, c, res; cin >> n;
  rep(i, n) {
    cin >> a >> b >> c;
    if (b == 0 && c == 0) res = 1;
    else if (b == 0) res = 0;
    else res = exp(b, c, 1) % (MOD-1);

    if (a == 0 && res == 0) cout << 1 << ln;
    else if (a == 0) cout << 0 << ln;
    else cout << (exp(a, res, 0) % MOD) << ln;
  }
}

int main() {
  flash;
  solve();
  return 0;
}