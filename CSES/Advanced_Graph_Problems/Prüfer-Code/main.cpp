#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 1;
int n, p, prv, total;
int cnt[maxN], pcode[maxN];
priority_queue<int, vector<int>, greater<int>> pq;

void solve() {
  cin >> n;

  for (int i = 1; i <= n - 2; ++i) {
    cin >> p;
    pcode[i] = p;
    ++cnt[p];
  }

  for (int i = 1; i <= n; ++i) {
    if (!cnt[i]) pq.push(i);
  }

  for (int i = 1; i <= n - 2 && !pq.empty(); ++i) {
    int u = pq.top(), v = pcode[i]; pq.pop();
    cout << u << " " << v << "\n";
    --cnt[v];
    if (!cnt[v]) pq.push(v);
  }

  if (pq.size() == 2) {
    int u = pq.top(); pq.pop();
    int v = pq.top(); pq.pop();

    cout << u << " " << v;
  }

}


int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  solve();
  return 0;
}