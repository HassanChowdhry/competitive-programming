#include <bits/stdc++.h>
using namespace std;

const int oo = 1e9 + 7;
const int N = 1e6;
long long n, m, modinv_n;
long long ans;
long long l_gcd[N + 1];

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

long long f_gcd(int a, int b) {
  if (b == 0) return a;
  return f_gcd(b, a % b);
}

void solve() {
  cin >> n >> m;
  modinv_n = fastpow(n, oo-2);
  // this will use burnsids lemma
  // 1 / n * sum ( c(k) )
  // ck = m ^ gcd(k, n)
  
  // can think of this as more a similar cycle type question
  // after k rotations in the necklace, block of pearls of 
  // size will be at gcd(k, n)

  // gcd will be log(n)

  for (int i = 1; i <= n; ++i) {
    l_gcd[i] = f_gcd(i, n);
  }

  ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans = (ans + 1LL * fastpow(m, l_gcd[i])) % oo;
  }

  ans = (ans * modinv_n) % oo;

  cout << ans;
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  // int t; cin >> t;
  // while(t--)
  solve();
  return 0;
}