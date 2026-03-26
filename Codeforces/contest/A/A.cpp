#include <bits/stdc++.h>
using namespace std;

void solve() {
  long long n, c, k; cin >> n >> c >> k;
  vector<long long> nums(n);
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }
  sort(nums.begin(), nums.end());
  for (long long i: nums) {
    if (i > c) continue;
    long long l = c - i;
    if (k >= l) {
      c += c;
      k -= l;
    } else {
      c += i + k;
      k = 0;
    }
  }

  cout << c << "\n";
}

int main() {
  cin.tie(0); cout.tie(0);

  int t; cin >> t;
  while (t--)
  solve();
  return 0;
}