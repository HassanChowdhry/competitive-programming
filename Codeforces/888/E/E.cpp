#include <bits/stdc++.h>
using namespace std;

int a[20];
int b[20];

void solve() {
  int n, m; cin >> n >> m;
  int half = (n + 1) / 2;

  for (int i = 0; i < half; ++i) {
    cin >> a[i];
  }
  
  for (int i = 0; i < (n - half); ++i) {
    cin >> b[i];
  }

  auto unmask_a = [&](int mask) -> int {
    int res = 0;
    for (int bit = 0; bit < half; ++bit) {
      if ((mask >> bit & 1) == 1) { // if that bit is on 
        res = (res + a[bit]) % m;
      }
    }

    return res;
  };

  auto unmask_b = [&](int mask) -> int {
    int res = 0;
    for (int bit = 0; bit < (n - half); ++bit) {
      if ((mask >> bit & 1) == 1) { // if that bit is on 
        res = (res + b[bit]) % m;
      }
    }

    return res;
  };

  // cout << n << " " << (n - half) << " " << half << "\n";

  set<int> left;
  for (int mask = 0; mask < (1 << half); ++mask) {
    left.insert(
      unmask_a(mask)
    );
  }

  int best = *left.rbegin(); // highest sum? 
  for (int mask = 0; mask < (1 << (n - half)); ++mask) {
    int sum = unmask_b(mask);
    // a possible answer is left best + an answer from the new right array?
    // but why is the rest not possible?
    // I see, we are searching for the combo that will generate the closes to anything below m
    best = max(
      best,
      *prev(left.lower_bound(m - sum)) + sum // this will always be less than m
    );
  }

  cout << best << "\n";
}

int main() {
  cin.tie(0); cout.tie(0);
  ios_base::sync_with_stdio(0);
  solve();
  return 0;
}