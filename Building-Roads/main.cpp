#include <bits/stdc++.h>
# define ll long long
# define pb push_back
# define all(a) a.begin(),a.end()
# define flash ios_base::sync_with_stdio(false);cin.tie(NULL);
# define test int t;cin>>t;while(t--)
# define loop(n) for(int i=0;i<n;++i)
# define loopx(x, n) for(int i=x;i<n;++i)
# define input(arr,n);for(int i=0;i<n;++i)cin>>arr[i];
# define nline "\n"
using namespace std;
int MOD=1000000007;
bool valid(int x,int y,int n,int m){return x>=0 && x<n && y>=0 && y<m;}
int powMod(int a,int n){ ll ans=1;for(int i=1;i<=n;i++){ ans=(ans*a)%MOD;}return ans%MOD; }


int find(int x, vector<int>& parent) {
  if (x == parent[x]) { return parent[x]; }
  parent[x] = find(parent[x], parent);
  return parent[x];
}

void onion(int x, int y, vector<int>& parent, vector<int>& rank) {
  int px = find(x, parent), py = find(y, parent);

  if (px == py) { return; }

  if (rank[px] >= rank[py]) {
    parent[py] = px;
    rank[px] += rank[py];
  } else {
    parent[px] = py;
    rank[py] += rank[px];
  }
}

void solve() {
  int n, m, x, y; cin >> n >> m;
  vector<int> parent(n+1), rank(n+1, 1); set<int> unique;
  loopx(1, n+1) { parent[i] = i; }

  loop(m) {
    cin >> x >> y;
    onion(x, y, parent, rank);
  }

  loop(n) {
    find(i+1, parent); unique.insert(parent[i+1]);
  }

  if (unique.size() == 1) { cout << 0 << nline; return; }

  cout << unique.size()-1 << nline;
  int l = 1, r = 2, pl, pr;
  while (r <= n) {
    pl = find(l, parent), pr = find(r, parent);
    if (pl != pr) { 
      cout << parent[l] << " " << parent[r] << nline;
      onion(pl, pr, parent, rank);
    }
    ++r;
  }

}

int main() {
  flash
  solve();
  return 0;
}