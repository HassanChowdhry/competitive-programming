#include <bits/stdc++.h>
using namespace std;

long long p, q;
long long a, b, c, d;
long long g1, g2;
void solve() {
  cin >> p >> q;

  // b = (2pr - 2qr -p)
  // a = p
  // c = pr (r - 1)
  // d = b^2 - 4ac
  // g = -b +- sqrt(d) / 2a
  for (int r = 1; r <= 1000000; ++r) {
    a = p;
    b = (2 * p * r) - (2 * q * r) - p;
    c = p * r * ( r - 1 );
    d = (b * b) - (4 * a * c);
    if (d < 0) continue;
    // cout << a << " " << b << " " << c << "  " << d << "\n";
    g1 = (-b + sqrt(d)) / (2 * a);
    g2 = (-b - sqrt(d)) / (2 * a);
    // cout << g1 << " " << g2 << "\n";

    if (g1 >= r) {
      long long l = p * (r + g1) * (r + g1 - 1);
      long long rr = 2 * q * r * g1;
      if (l == rr) {
        cout << r << " " << g1 << "\n";
        return;
      }
    }

    if (g2 >= r) {
      long long l = p * (r + g2) * (r + g2 - 1);
      long long rr = 2 * q * r * g2;
      if (l == rr) {
        cout << r << " " << g2 << "\n";
        return;
      }
    }
  }
  cout << "IMPOSSIBLE";
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  solve();
  return 0;
}