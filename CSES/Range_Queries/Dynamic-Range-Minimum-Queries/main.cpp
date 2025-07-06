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
int MOD=1000000007;

const int N = 200005;
ll tree[2*N];
int n;
void upd(ll k, ll x){
    k+=n;
    tree[k]=x;k>>=1;
    while(k>=1){
        tree[k] = min(tree[2*k], tree[2*k+1]);
        k>>=1;
    }
}
ll qry(ll a, ll b){
    a+=n, b+=n;
    ll s = MOD;
    while(a<=b){
        if (a&1) s = min(s,tree[a++]); //a is right child
        if (~b&1) s = min(s,tree[b--]); // b is left child
        a>>=1, b>>=1;
    }
    return s;
}

void solve() {
  ll m, num; cin >> n >> m;
  rep(i, n) {
    cin >> num;
    upd(i, num);
  }
  ll t, a, b;
  rep(i, m) {
    cin >> t >> a >> b;
    if (t == 1) {
      ll x = tree[a-1+n];
			upd(a-1, b);
    } else {
      cout << qry(a-1, b-1) << ln;
    }
  }
}

int main() {
  flash;
  solve();
  return 0;
}