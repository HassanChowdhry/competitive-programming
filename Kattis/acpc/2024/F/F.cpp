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
bool valid(int x,int y,int n,int m){return x>=0 && x<n && y>=0 && y<m;}
int powMod(int a,int n){ ll ans=1;for(int i=1;i<=n;i++){ ans=(ans*a)%MOD;}return ans%MOD; }

void solve() {
  int n; cin >> n;
  if (n <= 2) { cout << 0 << ln; return; }
  vector<ll> nums(n, 0);
  vector<pair<ll, ll>> pre(n, {0, 0}), suf(n, {0, 0});
  rep(i, n) cin >> nums[i];

  pre[0] = { nums[0], 0 };
  suf[n-1] = { nums[n-1], n-1 };

  for (int i = 1; i < n; i++) {
    pre[i] = pre[i-1];
    if (nums[i] >= pre[i].fs) pre[i] = {nums[i], i};
  }
  for (int i = n-2; i >= 0; i--) {
    suf[i] = suf[i+1];
    if (nums[i] >= suf[i].fs) suf[i] = {nums[i], i};
  }

  ll res = 0, pocket = 0;
  int currL = -1, currR = -1;

  for (int i = 0; i < n; ++i) {
    ll mn = min(pre[i].fs, suf[i].fs);

    if (currL != pre[i].sc || currR != suf[i].sc) {
      pocket = 0;
      currL = pre[i].sc;
      currR = suf[i].sc;
    }
    if (nums[i] < mn) pocket += (mn - nums[i]);
    res = max(res, pocket);
  }

  cout << res;
}

int main() {
  flash;
  // int t; cin >> t;
  // rep(i, t) 
  solve();
  return 0;
}