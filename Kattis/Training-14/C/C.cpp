#include <bits/stdc++.h>
using namespace std;

const int maxN = 5e5;
long long n, q, R, M, k, Minv;

long long extended_gcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long d = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

long long inv(long long a, long long m) {
    long long x, y;
    long long g = extended_gcd(a, m, x, y);
    if (g != 1) return -1;
    return (x % m + m) % m;
}


void solve() {
  cin >> n >> q;
  k = n;
  M = 1;
  Minv = 1;
  R = 0;  

  vector<long long> p(n + 1);

  for (int i = 1; i <= n; ++i) {
    p[i] = i;
  }

  char t; long long x;
  while (q--) {
    cin >> t >> x;


    if (t == '?') {
      if (x > k) { cout << -1 << "\n"; continue; }
      long long c = x-1;
      long long q = ((c - R) % k + k) % k * Minv % k;
      cout << p[q+1] << "\n";

    } else if (t == '*') {
      x %= k;
      long long gcd = __gcd(k, x);
      if (gcd == 1) {
        R = (R * x) % k;
        M = (M * x) % k;
        Minv = Minv * inv(x, k) % k;
        continue;
      }
      long long nk = k / gcd;
      vector<long long> np(nk+1, -1);
      for (int i = 1; i <= k; ++i) {
        if (p[i] == -1) continue;
        long long c = (M * (i-1) + R) % k;
        long long c2 = c * x % k;
        np[c2/gcd+1] = p[i];
      }
      
      p.swap(np);
      k = nk;
      R = 0;
      M = 1;
      Minv = 1;
    } else if (t == '+') {
      R = (R + x) % k;
    }
  }
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  solve();
  return 0;
}