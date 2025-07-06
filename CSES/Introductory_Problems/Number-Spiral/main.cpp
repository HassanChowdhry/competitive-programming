#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)
#define rep(i,n) for(int i=0;i<n;++i)
#define ln "\n"

void solve() {
  ll n, col, row, left, right; cin >> n;

  rep(_, n) {
    cin >> row >> col;
    if (col == 1 && row == 1) { cout << 1 << ln; continue; }
    
    if (col > row) {
      right = col * col;
      left = (col - 1) * (col - 1) + 1;

      if (col % 2) { cout << right - (row - 1) << ln; }
      else { cout << left + (row - 1) << ln; }
    } else if (row > col) {
      right = row * row;
      left = (row - 1) * (row - 1) + 1;

      if (row % 2 == 0) { cout << right - (col - 1) << ln; }
      else { cout << left + (col - 1) << ln; }
    } else {
      right = col * col;
      cout << right - (row - 1) << ln;
    }
  }
}

int main() {
  flash;
  solve();
  return 0;
}