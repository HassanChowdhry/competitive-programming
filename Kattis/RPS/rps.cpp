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
  string F, S; cin >> F >> S;

  while (F != "E" && S != "E") {
    int N = F.size();
    int p1 = 0, p2 = 0;

    for (int j = 0; j < N; ++j) {
      if (F[j] == S[j]) continue;
      if ((F[j] == 'R' && S[j] == 'S') || 
          (F[j] == 'P' && S[j] == 'R') || 
          (F[j] == 'S' && S[j] == 'P')
      ) ++p1;

      if ((S[j] == 'R' && F[j] == 'S') || 
          (S[j] == 'P' && F[j] == 'R') || 
          (S[j] == 'S' && F[j] == 'P')
      ) ++p2;      
    }

    cout << "P1: " << p1 << ln;
    cout << "P2: " << p2 << ln;
    cin >> F >> S;
  }
}

int main() {
  flash;
  // int t; cin >> t;
  // rep(i, t) 
  solve();
  return 0;
}