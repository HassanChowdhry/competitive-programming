#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)
#define rep(i,n) for(int i=0;i<n;++i)
#define ln "\n"

void rec(int n, string curr, set<string>& st, vector<int>& frq) {
  if (curr.size() == n) 
    { st.insert(curr); return; }
  
  for (int i = 0; i < 26; ++i) {
    if (frq[i] == 0) continue;
    char c = i + 'a';
    --frq[i];
    rec(n, curr + c, st, frq);
    ++frq[i];
  }
}
void solve() {
  string in; cin >> in;
  int n = in.size();
  set<string> st; 
  vector<int> frq(26, 0);
  for (char c : in) ++frq[c - 'a'];

  rec(n, "", st, frq);  

  cout << st.size() << ln;
  for (string curr: st) cout << curr << ln;
}

int main() {
  flash;
  solve();
  return 0;
}