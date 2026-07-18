#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll maxN = 1e12;
const ll sqrtN = 1e6;
ll n;
int primes[sqrtN+1];
vector<int> p;

// segmented sieves: https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html
void sieves() {
  for (int i = 2; i <= sqrtN; ++i) primes[i] = 1;

  for (int i = 2; i*i <= sqrtN; ++i) {
    if (primes[i]) {
      for (int j = i * i; j <= sqrtN; j += i) {
        primes[j] = 0;
      }
    }
  }

  for (int i = 2; i <= sqrtN; ++i) {
    if (primes[i]) p.push_back(i);
  }
}

int isprime(ll x) {
  if (x <= sqrtN) return primes[x];

  ll sq = sqrt(x);
  for (ll prime: p) {
    if (prime > sq) break;
    if (x % prime == 0) return 0;
  }

  return 1;
}

void solve() {
	cin >> n;
  ++n;
  while (!isprime(n)) {
    ++n;
  }

  cout << n << "\n";
	
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  sieves();
	int t; cin >> t;
  while (t--) solve();
	return 0;
}