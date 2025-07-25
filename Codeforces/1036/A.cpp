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
int MOD=1000000007;

void solve() {
  int n; cin >> n;
  vi nums(n, 0); input(nums, n);
  vi sorted_nums(nums);
  sort(sorted_nums.begin(), sorted_nums.end());

  int skip = 0;
  set<int> skip_list;

  for (int i = 0; i < n; ++i) {
    if (nums[i] == sorted_nums[i]) { ++skip; skip_list.insert(i); }
  }

  if (skip == n) { cout << "NO" << ln; return; }

  cout << "YES" << ln;
  cout << (n - skip) << ln;
  rep(i, n) {
    if (skip_list.count(i)) continue;
    cout << nums[i] << " ";
  }
  cout << ln;
}

int main() {
  flash;
  int t; cin >> t;
  rep(_, t) solve();
  return 0;
}