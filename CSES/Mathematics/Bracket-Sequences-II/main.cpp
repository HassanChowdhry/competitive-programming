#include <bits/stdc++.h>
using namespace std;

/**
 * Theres a couple of cases here, we have to recall that 
 * a valid sequence A can be split to 2 valid sequences A = A * B
 * and 2 valid seq A and B can be AB sequence.
 * AND if a sequence was invalid at any point it will be invalid in any
 * subsequent place
 * 
 * Case 1, there was an invalid in the given pref:
 *  return 0
 * Case 2: A was valid AND is a complete seq, number of remaining
 *  is the catalan of (N - open - closed)
 * Case 3: open > closed and valid till now, here we need to make sure 
 * that we remain valid throuhout and that the ending number of open - close be 0
 * in such a case we can choose remaining and (remaining - (open - closed) / 2)
 * as we need to make closed = to open and then make sure they remain at 0 by doing both ops
 * now we need to make sure we never go closed > open, rem choose rem - (rem + balance + 2 / 2)
 * this is the conf for invalid, simply remove from the original calc
 * A - B = the answer...
 */
const int oo = 1e9 + 7;
const long long maxN = 1e6;
long long fact[maxN + 1], invfact[maxN + 1];
long long N, m, open, closed;
string s;

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

void _fact() {
	fact[0] = 1;
	for (int i = 1; i <= maxN; ++i) {
		fact[i] = fact[i - 1] * i % oo;
	}

	for (int i = 0; i <= maxN; ++i) {
		invfact[i] = fastpow(fact[i], oo-2);
	}
}

// CATALAN numbers
// inv(n + 1) * (2n choose n)
// (2n choose n) = 2n! * inv(n!) * inv(2n-n!)
void catalan(int n) {
	if (n % 2) {
		cout << 0;
		return;
	}
	m = n / 2LL;

	long long inv_m_1 = fastpow(m + 1, oo-2); // inv of N mod M, if M is prime is N^(M-2);
	long long c_m = inv_m_1 % oo * fact[n] % oo * invfact[m] % oo * invfact[m] % oo;
	cout << c_m;
}

long long choose(long long a, long long b) {
  long long ans = fact[a] * (invfact[b] * invfact[a - b] % oo) % oo;
  return ans;
}

void solve() {
  cin >> N >> s;
  open = closed = 0;

  for (char c : s) {
    if (c == '(') ++open;
    else if (c == ')') ++closed;

    if (open < closed) {
      cout << 0;
      return;
    }
  }

  long long rem = N - open - closed;
  long long b = open - closed;
  
  if(closed + rem < open) {
    cout << 0;
    return;
  }

  if (open == closed) {
    catalan(N - open - closed);
    return;
  }

  if (rem == b) {
    cout << 1;
    return;
  }

  // (m choose (m - b) / 2) - (m choose (m + b + 2) / 2)
  // b = balance left
  // m = remaining after prefix
  // cout << rem << " " << b << "\n";
  long long y = (rem - b) / 2LL;
  long long A = choose(rem, y);
  // cout << y << "\n";
  y = (rem + b + 2) / 2;
  // cout << y << "\n";
  long long B = choose(rem, y);
  // cout << "\n" << "\n";
  
  long long ans = ((A - B) % oo + oo) % oo;
  cout << ans;
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  // int t; cin >> t;
  // while(t--)
  _fact();
  solve();
  return 0;
}