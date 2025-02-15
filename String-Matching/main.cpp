#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fs first 
#define sc second 
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)
#define rep(i,n) for(int i=0;i<n;++i)
#define repx(i,x,n) for(int i=x;i<n;++i)
#define input(arr,n);for(int i=0;i<n;++i)cin>>arr[i]
#define ln "\n"

void solve() {
  string str, pattern; cin >> str >> pattern; 
  int n = str.size(), m = pattern.size();
  vector<int> lps(m, 0);
  // lps table
  int pre = 0, suf = 1;
  while (suf < m) {
    if (pattern[pre] == pattern[suf])
      lps[suf++] = ++pre;
    else {
      if (pre == 0) ++suf;
      else pre = lps[pre - 1];
    }
  }

  int i = 0, j = 0, res = 0;
  while (i < n) {
    if (str[i] == pattern[j]) { 
      ++i; ++j;
      if (j == m) {
        ++res; j = lps[j - 1];
      }
    }
    else {
      if (j == 0) ++i;
      else j = lps[j - 1];
    }
  }

  cout << res;
}

int main() {
  flash;
  solve();
  return 0;
}