#include <bits/stdc++.h>
using namespace std;

const long long maxN = 1e12;
vector<long long> tri;

void find_tri() {
  long long x = 1;
  long long i = 1;

  while (x <= maxN) {
    tri.push_back(x);
    x = (i) * (i + 1LL) / 2LL;
    ++i;
  }
}

void solve() {
	long long n; cin >> n;
  // any number X can be rep as a sum of at most 3 triangle numbers
  // case 1: X is a triangle number -> 8x+1 is a perfect square = triangle number
  // see proof for why or X = (n (n + 1)) / 2
  if (binary_search(tri.begin(), tri.end(), n)) {
    cout << 1 << "\n";
    return;
  }

  // case 2: X is a sum of 2 triangle numbers
  // if 8X + 2 = a1^2 + a2^2
  int ok = 0;

  int l = 0, r = tri.size()-1;

  while (l <= r) {
    long long curr = tri[l] + tri[r];
    if (curr == n) {
      ok = 1; break;
    } else if (curr < n) {
      ++l;
    } else {
      --r;
    }
  }
  

  if (ok) {
    cout << 2 << "\n";
    return;
  }

  // case 3: no other case = this
  cout << 3 << "\n";
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  find_tri();
	int t; cin >> t;
  while (t--) solve();

	return 0;
}