#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fs first 
#define sc second
#define mod(num, n) (num % n + n) % n
#define all(a) a.begin(),a.end()
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)
#define rep(i,n) for(int i=0;i<n;++i)
#define input(arr,n);for(int i=0;i<n;++i)cin>>arr[i]
#define ln "\n"

void solve() {
  ll n, num, total = 0; cin >> n;
  vector<ll> nums(n);
  map<ll, ll> mp;
  ll prefix = 0, md = 0;
  rep(i, n) {
    cin >> num; prefix += num;
    md = mod(prefix, n); mp[md] += 1;
  }

  for (auto i : mp) {
    ll val = i.sc;
    if (i.fs == 0) total += ((val * (val + 1)) / 2);
    else total += ((val * (val - 1)) / 2);
  }

  cout << total;
}

int main() {
  flash;
  solve();
  return 0;
}