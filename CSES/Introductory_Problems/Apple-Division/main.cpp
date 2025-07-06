#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)
#define rep(i,n) for(int i=0;i<n;++i)
#define per(i,n) for(int i=n-1;i>=0;--i)
#define input(arr,n);for(int i=0;i<n;++i)cin>>arr[i]
#define ln "\n"

ll rec(ll n, ll i, ll curr, ll minn, vector<ll>& arr, ll total) {
  if (i >= n) return abs((total - curr) - curr);
  ll lmin = min(minn, abs((total - curr) - curr));

  ll cmin = min(
    rec(n, i + 1, curr + arr[i], lmin, arr, total),
    rec(n, i + 1, curr, lmin, arr, total)
  );

  return min(cmin, lmin);
}
void solve() {
  ll n; cin >> n;
  vector<ll> arr(n);
  ll total = 0; ll in; 
  rep(i, n) { cin >> in; arr[i] = in; total += in; }

  cout << rec(n, 0, 0, total, arr, total);
} 

int main() {
  flash;
  solve();
  return 0;
}