#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, char>
#define fi first
#define se second

string s;
int n, m, a, b;
int pre['Z'][50005];
char DNA[] = {'A', 'T', 'G', 'C'};

void solve() {
  cin >> s >> m; n = s.size();

  for (int i = 1; i <= n; ++i) {
    for (char dna : DNA) {
      pre[dna][i] = (pre[dna][i-1] + (dna == s[i-1]));
    }
  }

  for (int i = 1; i <= m; ++i) {
    cin >> a >> b;
    int mx = 0;
    vector<ii> ans;
    for (char dna : DNA) {
      ans.push_back({pre[dna][b] - pre[dna][a-1], dna});
    }
    
    
    sort(ans.begin(), ans.end(), [](ii a, ii b) {
      if (a.fi != b.fi) return a.fi > b.fi;
      if (a.se == 'A' || b.se == 'A') return a.se == 'A';
      if (a.se == 'T' || b.se == 'T') return a.se == 'T';
      if (a.se == 'G' || b.se == 'G') return a.se == 'G';
    });
    
    for (auto [x, dna] : ans) {
      cout << dna ;
      // cout << x << " " << dna << " ";
    } cout << "\n";
    // }
  }
}

// TACG
// TCGA
// GATC

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  solve();
  return 0;
}