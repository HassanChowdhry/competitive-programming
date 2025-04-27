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

ll exp(ll a, ll b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  if (b == 2) return (a * a) % MOD;
  
  if (b % 2) {
    return ((exp(a, b / 2) * exp(a, b / 2) % MOD) * a) % MOD;
  }

  return (exp(a, b / 2) * exp(a, b / 2)) % MOD;
}

void solve() {
  ll n, a, b; cin >> n;
  rep(i, n) {
    cin >> a >> b;
    if (a == 0 && b == 0) cout << 1 << ln;
    else if (a == 0) cout << 0 << ln;
    else cout << (exp(a, b) % MOD) << ln;
  }
}

int main() {
  flash;
  solve();
  return 0;
}