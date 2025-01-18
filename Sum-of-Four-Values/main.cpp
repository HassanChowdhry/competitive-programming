#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define fs first
#define sc second
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)
#define input(arr,n);for(int i=0;i<n;++i)cin>>arr[i]
#define rep(i,n) for(int i=0;i<n;++i)
#define rem(mp, el) if(mp[el]==0)mp.erase(el)
#define ln "\n"
 
void solve() {
  ll n, target; cin >> n >> target;
  vector<pair<ll, ll>> nums(n);
  rep(i, n) { cin >> nums[i].fs; nums[i].sc = i + 1; }
  // precompute pair 
  // find complement in map
  sort(nums.begin(), nums.end());
  for (ll pivot = 0; pivot < n - 3; ++pivot) {
    for (ll piv2 = pivot + 1; piv2 < n - 2; ++piv2) {
      ll left = piv2 + 1,  right = n - 1;
      while (left < right) {
        ll sum = nums[pivot].fs + nums[piv2].fs + nums[left].fs + nums[right].fs;
        if (sum == target) 
          { cout << nums[pivot].sc << " " << nums[piv2].sc << " " << nums[left].sc << " " << nums[right].sc; return; }
        if (target < sum) { --right; }
        else { ++left; }
      }
    }
  }
  cout << "IMPOSSIBLE";
}
 
int main() {
  flash;
  solve();
  return 0;
}