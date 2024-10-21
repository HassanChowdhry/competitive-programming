#include <iostream>
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main() {
  int target;
  cin >> target;
  vector <int> dp(target+1, 0);

  dp[0] = 1;
  for (int i = 0; i < target; ++i) {
    if (!dp[i]) continue;

    for (int dice = 1; dice <= 6; ++dice) {
      if ((i + dice) <= target) 
        { dp[i+dice] = (dp[i+dice] + dp[i]) % MOD; }
    }
  }
  
  cout << dp[target];
}