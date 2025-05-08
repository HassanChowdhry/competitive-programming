# include <bits/stdc++.h>
# define int long long
# define pb push_back
# define flash ios_base::sync_with_stdio(false);cin.tie(NULL);
# define input(arr,n) for(int i=0;i<n;++i)cin>>arr[i];
# define rem(mp, el) if(mp[el]==0)mp.erase(el);
# define nline "\n"
using namespace std;
int MOD=1000000007;

void solve() {
  int n, k; cin >> n >> k;
  vector<int> nums(n, 0); input(nums, n);
  map<int, int> mp;
  int l = 0, r = 0, res = 0;

  while (r < n) {
    mp[nums[r]]++;
    
    while (l < r && (int) mp.size() > k) {
      res += (r - l);
      mp[nums[l]]--;
      rem(mp, nums[l]);
      ++l;
    } 

    ++r;
  }

  while (l < n) {
    res += (r - l);
    ++l;
  }

  cout << res - n;
}

signed main() {
  flash
  solve();
  return 0;
}