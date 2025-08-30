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


void matmul(vector<vl>& A, vector<vl>& B) {
  vector<vl> res(2, vl(2));

  res[0][0] = ((A[0][0] * B[0][0]) + (A[0][1] * B[1][0])) % MOD;
  res[0][1] = ((A[0][0] * B[0][1]) + (A[0][1] * B[1][1])) % MOD;
  res[1][0] = ((A[1][0] * B[0][0]) + (A[1][1] * B[1][0])) % MOD;
  res[1][1] = ((A[1][0] * B[0][1]) + (A[1][1] * B[1][1])) % MOD;

  A=res;
}

vector<vl> powM(vector<vl> matrix, ll n) {
  vector<vl> identity = { {1, 0}, {0, 1} }; // identity matrix

  while (n) {
    // if odd multiply by the identity
    if ( n % 2 ) matmul(identity, matrix);
    
    matmul(matrix, matrix);
    n /= 2;
  }

  return identity;
}


void solve() {
  ll n; cin >> n;
  if (n == 0 || n == 1) { cout << n; return; }
  // matrix fib: https://cp-algorithms.com/algebra/fibonacci-numbers.html
  // this is the matrix you need to multiply 
  /* 
    {fn, fn-1} * {1, 1}^n  =  {fn+1, fn}
    {0, 0}       {1, 0}     {0, 0}
    this matrix is the transition to proceed to the nth fib number. in problems like this you have to figure out the matrix
    this is specific to fib only 
  */
  vector<vl> matrix = { 
    { 1, 1 }, 
    { 1, 0 } 
  };
  vector<vl> M = powM(matrix, n-1);
  // vector<vl> fib = { 
  //   { 1, 0 }, 
  //   { 0, 0 } 
  // };
  
  // matmul(fib, M);
  cout << M[0][0] % MOD << ln;
}

int main() {
  flash;
  solve();
  return 0;
}