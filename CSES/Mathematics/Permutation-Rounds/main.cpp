#include <bits/stdc++.h>
using namespace std;

const int oo = 1e9 + 7;
const long maxN = 2e5 + 1;
int n;
int p[maxN], vis[maxN], L[maxN], spf[maxN];
long long divcnt[maxN];
vector<int> CL;

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
void sieve() {
  for (int i = 1; i < maxN; ++i) {
    spf[i] = i;
  }

  for (long i = 2; i * i < maxN; ++i) {
    // for each d, harmonic sum nlogn
    if (spf[i] == i) {
      for (long j = i * i; j < maxN; j += i) {
        if (spf[j] == j) {
          spf[j] = i;
        }
      }
    }
  }
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> p[i];

  // find cycle lens of i -> p(i) -> p(p(i)) -> ....
  // this will give you all cycles of when they get back to their original pos
  // this may vary so we need the intesection fo all individual lens
  // in other words we need the LCM of unique cycles
  // computing this is expensive so we need prime factors
  // and we need max of each prime factor

  for (int i = 1; i <= n; ++i) {
    if (vis[i]) {
      L[i] = L[vis[i]];
      continue;
    }
    
    vis[i] = i;
    ++L[i];
    int j = p[i];

    while (j != i) {
      ++L[i];
      vis[j] = i;
      j = p[j];
    }

    CL.push_back(L[i]);
  }

  for (int len: CL) {
    // cout << len << " ";
    int x = len;
    int pnum = spf[x];
    long long pcnt = 0;
    while (x != 1) {
      x /= pnum;
      ++pcnt;
      if (spf[x] != pnum) {
        divcnt[pnum] = max(divcnt[pnum], pcnt);
        pnum = spf[x];
        pcnt = 0;
      }
    }
  }
  // cout << "\n";

  long long ans = 1;
  for (long long i = 2; i <= n; ++i) {
    // cout << "i: " << i << " divcnt : " <<  divcnt[i] << "\n";
    if (divcnt[i]) {
      ans = (ans * fastpow(i, divcnt[i])) % oo;
    }
  }

  cout << ans;

  // for (int i = 1; i <= n; ++i) {
  //   cout << "i: " << i << " L[i] " << L[i] << " vis[i] " << vis[i] << "\n";
  // }
  
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  // int t; cin >> t;
  // while(t--)
  sieve();
  solve();
  return 0;
}