#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5+5;
const int maxM = 'z' + 5;
int n, x, y, m;
string in;
set<int> suc_cand[maxM];
int valid_suc[maxM][maxM];
string query[maxN];
int valid[maxN];


void solve() {
  cin >> n >> x >> y;

  for (char c = 'a'; c <= 'z'; ++c) {
    cin >> m >> in;
    for (char h : in) {
      valid_suc[c][h] = 1;
    }
  } 

  for (int i = 1; i <= n; ++i) {
    cin >> in; query[i] = in;
    int ok = 1;
    int z = in.size();
    for (int j = 0; j < z - 1; ++j) {
      if (!valid_suc[in[j]][in[j+1]]) {
        ok = 0; break;
      }
    }

    valid[i] = ok;
    if (ok)
      suc_cand[in[0]].insert(z);
  }

  for (int i = 1; i <= n; ++i) {
    if (!valid[i]) {
      cout << "Get meowt!\n"; continue;
    }
    
    if (query[i].size() >= x && query[i].size() <= y) {
      cout << "Feline good!\n"; continue;
    }
    
    int ok = 0;
    char last = query[i][query[i].size() - 1];

    for (char first = 'a'; first <= 'z'; ++first) {
      // cout << " last: " << last << " first: " << first << "\n";
      if (valid_suc[last][first]) {
        int lo = x - query[i].size();
        int hi = y - query[i].size();

        auto it = suc_cand[first].lower_bound(lo);

        ok |= (it != suc_cand[first].end() && *it <= hi);
        if (ok) break;
        // cout << ok << "\n";
      }
      if (ok) break;
    }

    if (ok) cout << "Feline good!\n";
    else cout << "Get meowt!\n";
  }
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  solve();
  return 0;
}