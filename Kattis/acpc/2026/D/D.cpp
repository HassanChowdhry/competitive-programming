#include <bits/stdc++.h>
using namespace std;

string s;
int n;
long long bits[2000005];

void solve() {
  cin >> s; n = s.size();

  for (int i = 0; i < n; ++i) {
    long long d = s[i] - '0';
    long long pw2 = n - i - 1;

    while (d > 0) {
      long long lg2 = log2(d);
      ++bits[pw2 + lg2];
      d -= (1LL << lg2);
      long long step = pw2 + lg2;
      while (bits[step] == 2) {
        bits[step] = 0;
        ++bits[step + 1];
        ++step; 
      }
    }
  }

  int ok = 0;
  for (int i = 2000000; i >= 0; --i) {
    if (bits[i] == 1) {
      cout << "1";
      ok = 1;
    } else if (ok)  {
      cout << "0";
    }
  }
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  solve();
  return 0;
}