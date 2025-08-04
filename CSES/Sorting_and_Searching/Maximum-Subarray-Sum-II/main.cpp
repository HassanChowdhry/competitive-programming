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
int MOD=1000000007;

void solve() {
  int N, L, R; cin >> N >> L >> R;
  vector<ll> prefix(N + 1, 0);
  for (int i = 1; i <= N; ++i) { cin >> prefix[i]; prefix[i] += prefix[i-1]; }

  multiset<ll> heap;
  ll res = -INFINITY;
  // wtf
  for (int i = L; i <= N; ++i) {
    if (i > R) heap.erase(heap.find(prefix[i - R - 1]));
    heap.insert(prefix[i-L]);
    res = max(res, prefix[i] - *heap.begin());
  }

  cout << res;
}

int main() {
  flash;
  solve();
  return 0;
}