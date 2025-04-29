#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)
#define rep(i,n) for(int i=0;i<n;++i)
#define input(arr,n);for(int i=0;i<n;++i)cin>>arr[i]
#define ln "\n"

void solve() {
  int n; cin >> n;

  // legendre's formula
  ll total = 0;
  ll p = 5;
  while (floor(n / p) > 0) {
    total += floor(n / p);
    p *= 5;
  }

  cout << total; 
}

int main() {
  flash;
  solve();
  return 0;
}