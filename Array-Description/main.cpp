#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;

int main() {
  int n, m, num; cin >> n >> m;  
  int last = n-1;
  vector<vector<ll>> dp(n+1, vector<ll>(m+1, 0));
  vector<int> nums(n, 0);
  for (int i = 0; i < n; ++i)
    { cin >> num; nums[i] = num; dp[i][num] = 1;}
  
  if (nums[0] == 0)
    { for (int i = 1; i <= m; ++i ) dp[0][i] = 1; }

  ll left, middle, right;
  bool possible = true;
  for (int i = 0; i < n-1; ++i) {
    if (abs(nums[i] - nums[i+1]) > 1 && nums[i] != 0 && nums[i+1] != 0)
      { possible = false; break; }
    
    if (nums[i+1] == 0) {
      if (nums[i] == 0) {
        for (int j = 1; j <= m; ++j) {
            left = j-1 > 0 ? dp[i][j-1] : 0;
            middle = dp[i][j];
            right = j+1 <= m ? dp[i][j+1] : 0;
            dp[i+1][j] = (left + middle + right) % MOD;
        }
      } else {
            ll curr = dp[i][nums[i]];
            if (nums[i]-1 > 0)
              { dp[i+1][nums[i]-1] = curr; }
            dp[i+1][nums[i]] = curr;
            if (nums[i]+1 <= m)
              { dp[i+1][nums[i]+1] = curr; }
        }
    } else {
        if (nums[i] == 0) {
          left = nums[i+1]-1 > 0 ? dp[i][nums[i+1]-1] : 0;
          middle = dp[i][nums[i+1]];
          right = nums[i+1] + 1 <= m ? dp[i][nums[i+1]+1] : 0;
          dp[i+1][nums[i+1]] = (left + middle + right) % MOD;
        }
        else {
          dp[i+1][nums[i+1]] = dp[i][nums[i]];
        }
    }
  }

  ll res = 0;
  for (int i = 1; i <= m && possible; ++i) 
    { res = (res + dp[last][i]); }

  cout << res % MOD;
}