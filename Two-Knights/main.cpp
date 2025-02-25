#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fs first 
#define sc second 
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)
#define rep(i,n) for(int i=0;i<n;++i)
#define input(arr,n);for(int i=0;i<n;++i)cin>>arr[i]
#define ln '\n'
void solve() {
  int n; cin >> n;
  ll total, not_valid;

  for (ll i = 1; i <= n; ++i) {
    total = (i * i) * ( i * i - 1 ) / 2;
    not_valid = 4 * ( i - 1 ) * ( i - 2 );
    cout << total  - not_valid << ln;
  }
}

int main() {
  flash;
  solve();
  return 0;
}