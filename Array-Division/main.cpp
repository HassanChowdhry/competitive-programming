#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fs first 
#define sc second 
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)
#define rep(i,n) for(int i=0;i<n;++i)
#define input(arr,n);for(int i=0;i<n;++i)cin>>arr[i]
#define ln "\n"
int MOD=1000000007;

bool is_valid(vector<ll>& nums, ll n, ll mid, ll k) {
  ll subarrays = 1, curr_sum = 0;

  rep(i, n) {
    if (nums[i] > mid) return false;
    if (curr_sum + nums[i] > mid) {
      subarrays += 1; curr_sum = 0;
    }
    curr_sum += nums[i];
  }

  return subarrays <= k;
}

void solve() {
  ll n, k, sum = 0; cin >> n >> k;
  vector<ll> nums(n); 
  rep(i, n) { cin >> nums[i]; sum += nums[i]; }
  ll res = sum;
  ll l = 0, r = sum;
  while (l <= r) {
    ll mid = (r + l) / 2;
    bool check = is_valid(nums, n, mid, k);
    if (check) {
      res = mid; r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  cout << res;
}

int main() {
  flash;
  solve();
  return 0;
}