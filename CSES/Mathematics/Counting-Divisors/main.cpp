#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)
#define rep(i,n) for(int i=0;i<n;++i)
#define input(arr,n);for(int i=0;i<n;++i)cin>>arr[i]
#define ln "\n"
int MOD=1000000007;
int top=1000005;

void solve() {
  ll n, x;
  cin >> n;
  vector<ll> divs(top, 0);

  // pre calculate all divs
  for (ll i = 1; i < top; ++i) {
    for (ll j = i; j < top; j += i) {
      ++divs[j];
    }
  }

  rep(_, n) {
    cin >> x;
    cout << divs[x] << ln;
  }
}

int main() {
  flash;
  solve();
  return 0;
}