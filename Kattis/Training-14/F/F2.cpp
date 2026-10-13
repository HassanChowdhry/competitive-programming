
#include <bits/stdc++.h>
using namespace std;

long long a, b, c, d;
long long check;
// map<int, map<int, int>>;

const int maxN = 1 << 19;
unordered_set<int> dp[maxN];
int pos1[19], pos2[19];
int d1, d2, pos, ok;

bool valid(int mask, int c_mask) {
  long long ma = 0, mb = 0;
  for (int i = d1; i > 0; --i) {
    if (mask & (1 << (i - 1))) continue;;
    ma *= 10; 
    ma += pos1[i];
  }
  for (int i = d2; i > 0; --i) {
    if (c_mask & (1 << (i - 1))) continue;;
    mb *= 10; 
    mb += pos2[i];
  }
  // reconstruct a and b

  if (mb == 0) return 0;
  // ab = (double) ma / (double) mb;

  // cout << mask << " " << c_mask << "\n";
  // cout << ma << " " << mb << "\n";
  // cout << ab << " " << cd << "\n\n";
  bool res = (__int128)ma * d == (__int128)mb * c;
  if (res) {
    cout << "possible\n" << ma << " " << mb;
  }
  return res;
}

// I dont need to store it per say
// dp[0] and 1 bits are base cases
// 2 bits are made ny combing 2 1 bit masks
// 3 bits are made by combining 2 bit and 1 bit mask result
// each bit mask must store a mask of the same number of bit
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

  if (valid(0, 0)) return;

  dp[0].insert(0);
  for (int i = 1; i <= d1; ++i) {
    if (pos1[i] == 0) break;
    int mask = 1 << (i-1);
    for (int j = 1; j <= d2; ++j) {
      if (pos2[j] == 0) break;
      if (pos1[i] == pos2[j]) {
        int c_mask = 1 << (j-1);
        if (dp[mask].insert(c_mask).second) {
          ok = valid(mask, c_mask);
          if (ok) return;
        }
        // cout << mask << " :  " << c_mask << "\n";;
      }
    }
  }

  for (int mask = 1; mask < ( 1 << d1 ); ++mask) {
    int ones = __builtin_popcount(mask);
    if (ones > d1) continue;
    // cout << ones << "\n";

    // 0001 can go to 0011 0101 1001
    // using          0010 0100 1000
    // cout << "\n";

    for (int i = 1; i <= d1; ++i) {
      int bit = (1 << (i - 1));
      int next_mask = mask | bit;
      int next_ones = __builtin_popcount(next_mask);
      if (next_ones != ones + 1 || next_ones > d1) continue;
      // cout << mask << ": " << bit << "\n";

      for (int x : dp[mask]) {
        for (int y : dp[bit]) {
          int c_mask = x | y;
          // cout << x << " " << y << "\n";
          int c_ones = __builtin_popcount(c_mask);
          if (c_ones != next_ones || c_ones > d2) continue;
          if (dp[next_mask].insert(c_mask).second) {
            ok = valid(next_mask, c_mask);
            if (ok) return;
          }
        }
      }
    } 
  }


  if (ok) cout << "possible";
  else cout << "impossible";
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  solve();
  return 0;
}