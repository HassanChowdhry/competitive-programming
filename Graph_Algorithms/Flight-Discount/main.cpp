#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fs first 
#define sc second 
#define all(a) a.begin(),a.end()
#define mod(num, n) (num % n + n) % n
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)
#define test int t;cin>>t;while(t--)
#define rep(i,n) for(int i=0;i<n;++i)
#define repx(i,x,n) for(int i=x;i<n;++i)
#define per(i,n) for(int i=n-1;i>=0;--i)
#define input(arr,n);for(int i=0;i<n;++i)cin>>arr[i]
#define rem(mp, el) if(mp[el]==0)mp.erase(el)
#define ln "\n"
#define vi vector<int>
#define vl vector<ll>
#define vll vector<vl>
#define vlll vector<vll>
#define ppl pair<pair<ll, ll>, ll>

int MOD=1000000007;

void solve() {
  int n, k; cin >> n >> k;
  priority_queue<ppl, vector<ppl>, greater<ppl>> heap; // {cost, k,} from
  vlll adj(n + 1);
  vll vis(n + 1, vl(2, 0));
  ll from, to, cost, used;
  repx(i, 1, k + 1) {
    cin >> from >> to >> cost;
    adj[from].pb({ to, cost });
  }

  heap.push({{ 0, 0 }, 1});
  while (!heap.empty()) {
    cost = heap.top().fs.fs, used = heap.top().fs.sc, from = heap.top().sc; heap.pop();
    if (from == n) { cout << cost; return; }
    if (vis[from][used]) continue;
    vis[from][used] = 1;

    for (auto& p: adj[from]) {
      ll t = p[0], c = p[1];
      heap.push({{cost + c, used}, t});
      if (!used)
        heap.push({{cost + (c / 2), 1}, t});
    }
  }
}


int main() {
  flash;
  solve();
  return 0;
}