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

const int MAXN = 100;
ll fact[MAXN + 1], invfact[MAXN + 1];
ll modpow(ll a, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}
 
void init_fact() {
  fact[0] = 1;
  for (int i = 1; i <= MAXN; ++i) fact[i] = (fact[i-1] * i) % MOD;

  invfact[MAXN] = modpow(fact[MAXN], MOD - 2);
  for (int i = MAXN-1; i >= 0; --i) invfact[i] = (invfact[i+1] * (i + 1)) % MOD;
}

// combinations code
ll nCr(int n, int r) {
  if (r < 0 || r > n) return 0;
  return (((fact[n] * invfact[r] ) % MOD) * invfact[n - r] % MOD);
}

void solve() {
  init_fact();
}

int main() {
  flash;
  solve();
  return 0;
}