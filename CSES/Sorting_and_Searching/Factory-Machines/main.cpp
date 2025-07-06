#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL);
#define loop(n) for(int i=0;i<n;++i)
#define loopx(x, n) for(int i=x;i<n;++i)
#define input(arr,n);for(int i=0;i<n;++i)cin>>arr[i];
#define ln "\n"

bool valid(ll middle, vector<int>& nums, int n, int k) {
  ll res = 0;
  loop(n) 
    { res += min(middle / nums[i], (ll)1e9); } 
  
  return res >= k;
}

void solve() {
  int n, k; cin >> n >> k;
  vector<int> nums(n, 0); input(nums, n);
  ll l = 0, r = 1e18, middle, res = 0;

  while (l <= r) {
    middle = ((l + r) / 2);
    if (valid(middle, nums, n, k)) {
      res = middle;
      r = middle - 1;
    } else {
      l = middle + 1;
    }
  }

  cout << res;
}

int main() {
  flash
  solve();
  return 0;
}