#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fs first 
#define sc second
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)
#define rep(i,n) for(int i=0;i<n;++i)
#define repx(i,x,n) for(int i=x;i<n;++i)
#define input(arr,n);for(int i=0;i<n;++i)cin>>arr[i]
#define ln "\n"

void solve() {
  int n; cin >> n;
  ll runsum = (n * (n + 1)) / 2;
  if (runsum % 2) { cout << "NO"; return; }
  vector<int> left, right;
  ll lsum = 0, rsum = 0;

  for (int i = n; i > 0; --i) {
    if (lsum >= rsum) {
      rsum += i;
      right.pb(i);
    } else {
      lsum += i;
      left.pb(i);
    }
  }

  reverse(left.begin(), left.end());
  reverse(right.begin(), right.end());
  cout << "YES" << ln;
  cout << left.size() << ln;
  for (int z: left) cout << z << " ";
  cout << ln;
  cout << right.size() << ln;
  for (int z: right) cout << z << " ";
}

int main() {
  flash;
  solve();
  return 0;
}