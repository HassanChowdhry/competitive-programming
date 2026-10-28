#include <bits/stdc++.h>
using namespace std;

int b;
long long fact[1001];
long long dp[10000][4];
int oo = 676767677;

long long e, res;

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

void solve() {
  cin >> b;

  long long inv3 = fastpow(3, oo - 2) % oo;
  
  if (b == 3) {
    cout << 5 << " " << 1 << "\n"; return;
  }
  
  fact[0] = 1LL;
  
  for (int i = 1; i <= 1000; ++i) {
    fact[i] = (fact[i-1]*i) % oo;
  }

  if (b % 2 == 0) {
    e = (b - 1) / 2;
    res = (e * fact[b - 2]) % oo;
    cout << 2 << " " << res << "\n"; return;
  }

  if (b % 4 == 1) {
    res = fact[b - 1];
    cout << 2 << " " << res << "\n"; return;
  }

  // think of this in 
  // 1 + b^1 + b^n (mod 3)
  // case 1: b % 3 == 0, then its the number of div by three
  // case 2: b % 3 == 1, (1 + 1...), the number always sums up to a div by 3
  // case 3: b % 3 == 2, we get A + 2 * B which becomes ( A - B (mod 3))
  // we can either use closed form or dp to calculate this
  // dp[i][r] = dp[i - 1][(r - d[i]) % 3] + dp[i-1][r];
  if (b % 4 == 3) {
    cout << 3 << " ";

    if (b % 3 == 0) {
      long long three = (b - 1) / 3;
      res = (fact[b - 2] * three) % oo;
      cout << res << "\n";
      return;
    }

    if (b % 3 == 1) {
      cout << fact[b - 1] << "\n"; return;
    }

    

    // WAY 1
    // res = A - B (mod 3) ( number of ways to make pos of 1 and 2)
    if (b % 3 == 2) {
        res = (fact[b-1] * inv3) % oo;
        cout << res << "\n"; return;
        // cout << res << " FIRST ";
      }
      
    // WAY 2
    // if (b % 3 == 2) {
    //   dp[0][0] = 1;
    //   for (int d = 1; d < b; ++d) {
    //     long long start = min(d, (b - 1)/2);
    //     for (int i = start; i >= 1; --i) {
    //       for (int r = 0; r <= 2; ++r) {
    //         dp[i][r] = (dp[i-1][((r - d)%3+3)%3] + dp[i][r]) % oo;
    //       }
    //     }
    //   }
      
    //   res = dp[(b-1)/2][0] % oo * fact[(b-1)/2] % oo * fact[(b-1)/2] % oo;
    //   cout << res << " SECOND\n";
    //   return;
    // }

  }
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  // int t; cin >> t;
  // while(t--)
  solve();
  return 0;
}