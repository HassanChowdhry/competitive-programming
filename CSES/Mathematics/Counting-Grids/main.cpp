#include <bits/stdc++.h>
using namespace std;

const int oo = 1e9 + 7;
long long n, modinv_4;

long long fastpow(long long x, long long y) {
	long long res = 1;
	while (y > 0) {
		if (y & 1) {
			res = (res * x) % oo;
		}

		x = (x * x) % oo;
		y >>= 1;
	}

	return res;
}

// 3 cases for even / odd
// 0 rotation, 1 or 3 rotation, 2 rotaion
// how many make for each
  // case 1 : 0
    // easy 2 ^ (n * n)
  // case 2: 1/3
    // 4 unique visits before a revisit
      // 2 ^ (n * n / 4)
  // case 3: 180 roation
    // 2 ^ (n * n / 2)

void solve_even() {
  long long e0 = n * n;
  long long e1 = n * n / 4LL;
  long long e2 = n * n / 2LL;

  long long c0 = fastpow(2, e0) % oo;
  long long c1 = fastpow(2, e1) % oo;
  long long c3 = c1;
  long long c2 = fastpow(2, e2) % oo;

  long long ans = (c0 + c1 + c2 + c3) % oo;

  ans = (ans * modinv_4) % oo;

  cout << ans;
}

void solve_odd() {
  long long e0 = n * n;
  long long e1 = (n * n - 1) / 4LL + 1;
  long long e2 = (n * n + 1) / 2LL;

  long long c0 = fastpow(2, e0) % oo;
  long long c1 = fastpow(2, e1) % oo;
  long long c3 = c1;
  long long c2 = fastpow(2, e2) % oo;

  long long ans = (c0 + c1 + c2 + c3) % oo;

  ans = (ans * modinv_4) % oo;

  cout << ans;
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  // int t; cin >> t;
  // while(t--)
  cin >> n;
  if (n == 1) {
    cout << 2;
    return 0;
  }
  modinv_4 = fastpow(4LL, oo-2);
  if (n % 2) solve_odd();
  else solve_even();
  return 0;
}