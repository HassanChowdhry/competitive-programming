#include <bits/stdc++.h>
using namespace std;

long long a, b, c, d;
long long check;
// map<int, map<int, int>>;

const int maxN = 1 << 20;
map<long long, int> dp;
int pos1[20], pos2[20];
int frq[10];
int d1, d2, pos, ok;

// bp = (ap * d / c)
// we can create ap using masks (all subsequences)
// or bp * c = ap * d
// so we need some mask from b makes mb. 
// 1123 makes the same number, but we it will be made ONLY by removing the digits
// so we only need to know one way of making it ? 
// perhaps we can pregenerate that ? 
// the 0 is a bit tricky we have to make sure its invalid to generate numbers
// starting with 0
void solve() {
  cin >> a >> b >> c >> d;
  // cd = (double)c / (double)d;
  check = a;
  pos = 1;
  d1 = d2 = 0;
  while (check > 0) {
    pos1[pos] = check % 10;
    check /= 10LL;
    ++pos; ++d1;
  }
  check = b;
  pos = 1;
  while (check > 0) {
    pos2[pos] = check % 10;
    check /= 10LL;
    ++pos; ++d2;
  }

  for (int mask = 0; mask < (1 << d2); ++mask) {
    int zeros = 0;
    long long mb = 0;
    for (int i = d2; i > 0; --i) {
      if (mask & (1 << (i - 1))) {
        zeros += (pos2[i] == 0);
        continue;
      }

      if (mb == 0 && pos2[i] == 0) {
        mb = -1;
        break;
      }

      mb *= 10; 
      mb += pos2[i];
    }
    if (mb <= 0) continue;
    dp[mb] = mask;
  }

  for (int mask = 0; mask < (1 << d1); ++mask) {
    for (int i = 0; i <= 9; ++i) frq[i] = 0;
    long long ma = 0, mb = 0;
    for (int i = d1; i > 0; --i) {
      if (mask & (1 << (i - 1))) {
        ++frq[pos1[i]];
        continue;
      }

      if (ma == 0 && pos1[i] == 0) {
        ma = -1;
        break;
      }

      ma *= 10; 
      ma += pos1[i];
    }
    
    if (ma <= 0) continue;
    if (((__int128)ma * (__int128)d ) % c != 0) continue;
    __int128 mbb = ((__int128)ma * (__int128)d) / (__int128)c;

    if (mbb <= 0 || mbb > b) continue;
    mb = mbb;

    if (!dp.count(mb)) continue;
    int b_mask = dp[mb];

    for (int i = d2; i > 0; --i) {
      if (b_mask & (1 << (i - 1))) {
        --frq[pos2[i]];
      }
    }

    int ok = 1;
    for (int i = 0; i <= 9; ++i) {
      ok = frq[i] == 0;
      if (!ok) break;
    }
    if (ok) {
      cout << "possible\n";
      cout << ma << " " << mb;
      return;
    }
  }

  cout << "impossible";
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  solve();
  return 0;
}