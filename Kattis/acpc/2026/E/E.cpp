#include <bits/stdc++.h>
using namespace std;
long long n, ans;
int oo = 1e9 + 7;
map<long long, long long> dp;

long long rec(long long s) {
  // ++timer;
  // cout << timer << "\n";
  if (s < 0) {
    return 0;
  }
  
  if (dp[s]) {
    return dp[s];
  }
  if (s == 0) {
    dp[s]=1;
    return 1;
  }


  long long ways = 0;
  long long d = s % 2;
  
  for (long long i = d; i <= 9; i +=2) {
    ways = (ways + rec(((s-i) / 2LL))) % oo;
  }

  dp[s] = ways;

  return ways;
}

void solve() {
  cin >> n;

  long long ways = 0;
  long long d = n % 2;
  ways = rec(n);

  cout << ways << " ";
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  solve();
  return 0;
}