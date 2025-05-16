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

void solve() {
  int n; cin >> n;
  vector<ll> nums(n, 0); input(nums, n);
  set<int> visit;
  int l = 0;
  ll res = 0;

  rep(r, n) {
    while (visit.count(nums[r]) && l < r) {
      // cout << r << " " << l << " num " <<  r - l << ln;
      res += ( r - l );
      visit.erase(nums[l++]);
    }

    visit.insert(nums[r]);
  }

  while (l < n) {
    // cout << n << " " << l << " num " <<  n - l << ln;
    res += ( n - l );
    visit.erase(nums[l++]);
  }

  cout << res;
}

int main() {
  flash;
  solve();
  return 0;
}