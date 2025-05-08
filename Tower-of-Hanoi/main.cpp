#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)
#define rep(i,n) for(int i=0;i<n;++i)
#define ln "\n"

void rec(int curr, int start, int end, int mid, vector<pair<int, int>>& st) {
  if (curr < 1) return;

  rec(curr-1, start, mid, end, st);
  // cout << "block: " << curr << " start: " << start << " end: " << end << ln;
  st.pb({ start, end });
  rec(curr-1, mid, end, start, st);
}
void solve() {
  int n; cin >> n;
  vector<pair<int, int>> st;
  rec(n, 1, 3, 2, st);

  cout << st.size() << ln;
  for (const auto& [start, end]: st) 
    { cout << start << " " << end << ln; }
}

int main() {
  flash;
  solve();
  return 0;
}