#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main() {
  int n, t, ts = 0, snow; cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> t >> snow;
    if (t == 0)
      { ts += snow; }
    else 
      { ts = max(ts - snow, 0); }
  }
  
  cout << ts;
}