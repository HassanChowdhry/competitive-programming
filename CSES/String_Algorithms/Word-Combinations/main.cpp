#include <bits/stdc++.h>
using namespace std;

const int maxN = 5000;
const int maxk = 1e6;
const int oo = 1e9 + 7;
int k;
string s, w; 
int trie[maxk+1][26];
int end_[maxk+1];
long long dp[maxN + 5];
int node_count = 0;

void insert(string word) {
  
  int node = 0;

  for (char c: word) {
    if (trie[node][c - 'a'] == 0) {
      trie[node][c - 'a'] = ++node_count;
    }

    node = trie[node][c - 'a'];
  }

  end_[node] = 1;
}

void solve() {

  cin >> s >> k;
  int n = s.size();

  for (int i = 1; i <= k; ++i) {
    cin >> w;
    insert(w);
  }
  dp[n] = 1;

  for (int i = n - 1; i >= 0; --i) {
    // dp[i] = ways to make s[i..size];
    // dp[i] += dp[j + 1] where j is the end of a possible word
    int node = 0;
    for (int j = i; j < n; ++j) {
      if (trie[node][s[j] - 'a'] == 0) break;

      node = trie[node][s[j] - 'a'];

      if (end_[node]) dp[i] = (dp[i] + dp[j + 1]) % oo;
    }
  }

  cout << dp[0] << "\n";
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  // int t; cin >> t;
  // while(t--)
  solve();
  return 0;
}