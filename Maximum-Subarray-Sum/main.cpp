#include <bits/stdc++.h>
# define ll long long
using namespace std;

int main() {
  int n; cin >> n;  
  vector<ll> nums(n, 0);
  for (int i = 0; i < n; ++i)
    { cin >> nums[i]; }

  ll res = nums[0], curr = nums[0];
  for (int i = 1; i < n; ++i) 
    { curr = max(curr + nums[i], nums[i]); res = max(res, curr); }
  
  cout << res;
}