#include <bits/stdc++.h>
using namespace std;

void solve() {
  long long n; cin >> n;

  if (n == 10) {cout << -1 << "\n"; return;}
  if (n < 12) {cout << n << " " << 0 << "\n"; return;}

  long long m = n % 12LL;
  if (m != 10LL) {
    long long b = (n - m);
    cout << m << " " << b << "\n";
    return;
  }

  long long a = 22;
  long long b = n - a;
  cout << a << " " << b << "\n";
  
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  
  int t; cin >> t;
  while (t--)
  solve();
  
  return 0;
}