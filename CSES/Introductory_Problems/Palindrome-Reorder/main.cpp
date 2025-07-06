#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)
#define rep(i,n) for(int i=0;i<n;++i)
#define ln "\n"
int MOD=1000000007;

void solve() {
  string in; cin >> in;
  vector<int> frq(26, 0);

  for (char c: in) 
    ++frq[c - 'A'];

  int odd = 0, n = 0; 
  char c;
  rep(i, 26) {
    n += frq[i];
    if (frq[i] % 2) 
      { ++odd; --frq[i]; c = i + 'A'; }
    if (odd > 1) 
      { cout << "NO SOLUTION"; return; }
  }
  vector<char> res(n);
  int l = 0, r=n-1;
  rep(i, 26) {
    char chr = (char)('A'+i);
    rep(_, frq[i] / 2) 
      { res[l++] = chr; res[r--] = chr; }
  }

  if (c && n % 2) res[l] = c;
  
  for (char z: res)
    cout << z;
  
}

int main() {
  flash;
  solve();
  return 0;
}