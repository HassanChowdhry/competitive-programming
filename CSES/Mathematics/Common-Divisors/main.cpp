#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fs first 
#define sc second 
#define all(a) a.begin(),a.end()
#define mod(num, n) (num % n + n) % n
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)
#define test int t;cin>>t;while(t--)
#define rep(i,n) for(int i=0;i<n;++i)
#define repx(i,x,n) for(int i=x;i<n;++i)
#define per(i,n) for(int i=n-1;i>=0;--i)
#define input(arr,n);for(int i=0;i<n;++i)cin>>arr[i]
#define rem(mp, el) if(mp[el]==0)mp.erase(el)
#define ln "\n"
#define vi vector<int>
#define vl vector<ll>

void solve() {
  int n; cin >> n;
  vector<int> cnt(int(1e6+1));
  int res = 0, x, num, r;

  for (int i = 0; i < n; ++i) {
    cin >> num;
    x = sqrt(num);

    // count all divs 
    for (int j = 1; j <= x; ++j) {
      if (num % j == 0) {
        r = num / j;
        ++cnt[j];
        if (r != j) ++cnt[r];
        if (cnt[r] >= 2) res = max(res, r);
        if (cnt[j] >= 2) res = max(res, j);
      }
    }
  }
  
  cout << res;
}

int main() {
  flash;
  solve();
  return 0;
}