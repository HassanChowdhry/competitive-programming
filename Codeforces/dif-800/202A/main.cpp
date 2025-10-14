#include <bits/stdc++.h>
using namespace std;

int cnt[26];
void solve() {
  string s; cin >> s;
  char m = s[0];
  for (char c: s) {
    m = max(m, c);
    ++cnt[c - 'a'];
  }

  for (int i =0; i < cnt[m-'a']; ++i)
    cout << m;
}


int main() {
  solve(); 
  return 0;
}