#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fs first 
#define sc second 
#define all(a) a.begin(),a.end()
#define mod(num, n) (num % n + n) % n
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)
#define rep(i,n) for(int i=0;i<n;++i)
#define input(arr,n);for(int i=0;i<n;++i)cin>>arr[i]
#define ln "\n"
int MOD=1000000007;

bool cycleCheck(int node, int parent, map<int, vector<int>>& adj, map<int, int>& visit, deque<int>& dq) {
  if (visit[node] == 2) return false;
  visit[node] = 1;
  dq.push_back(node);
  for (int child: adj[node]) {
    if (child == parent) continue;
    if (visit[child] == 0) {
      bool x = cycleCheck(child, node, adj, visit, dq);
      if (x) return x;
    } else if (visit[child] == 1) {
      dq.push_back(child);
      return true;
    }
  }
  dq.pop_back();
  visit[node] = 2;
  return false;
}

void solve() {
  int n, m, c1, c2; cin >> n >> m;
  map<int, vector<int>> adj; map<int, int> visit; // 0: not visit, 1: visiting, 2: visited
  deque<int> dq;
  rep(_, m) {
    cin >> c1 >> c2;
    adj[c1].pb(c2);
    adj[c2].pb(c1);
  }

  rep(i, n)
    { bool x = cycleCheck(i+1, 0, adj, visit, dq); if (x) break; }
    
  while (!dq.empty() && dq.front() != dq.back()) dq.pop_front();
  if (dq.size() == 0) { cout << "IMPOSSIBLE"; return; }
  cout << dq.size() << ln;
  while (!dq.empty()) {
    cout << dq.front() << " ";
    dq.pop_front();
  }
}

int main() {
  flash;
  solve();
  return 0;
}