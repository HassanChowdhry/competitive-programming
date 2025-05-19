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
#define vi vector<int>
#define vl vector<ll>
#define ln "\n"
int MOD=1000000007;

int find(int x, vi& parent) {
  if (x == parent[x]) return parent[x];
  parent[x] = find(parent[x], parent);
  return parent[x];
}

int onion(int x, int y, vi& parent, vi& rank, int& max_num) {
  int px = find(x, parent), py = find(y, parent);

  if (px == py) return 0;

  if (rank[px] > rank[py]) {
    parent[py] = px; rank[px] += rank[py];
    max_num = max(max_num, rank[px]);
  } else {    
    parent[px] = py; rank[py] += rank[px];
    max_num = max(max_num, rank[py]);
  }

  return 1;
}

void solve() {
  int n, k; cin >> n >> k;
  int x, y; 
  vi parent(n+1, 0), rank(n+1, 1);
  int max_num = 0;
  rep(i, n+1) parent[i] = i; 
  int conn = n;
  rep(_, k) {
    cin >> x >> y;
    conn -= onion(x, y, parent, rank, max_num);
    cout << conn << " " << max_num << ln;
  }
}

int main() {
  flash;
  solve();
  return 0;
}