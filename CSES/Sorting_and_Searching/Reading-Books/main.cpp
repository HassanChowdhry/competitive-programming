#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)
#define rep(i,n) for(int i=0;i<n;++i)
#define input(arr,n);for(int i=0;i<n;++i)cin>>arr[i]
#define ln "\n"
int MOD=1000000007;

void solve() {
  ll n; cin >> n;
  vector<ll> time(n); input(time, n);
  if (n == 1) 
    { cout << time[0] * 2; return; }
  
  sort(time.begin(), time.end());
  ll sum = 0; rep(i, n - 1) { sum += time[i]; }
  ll largest = time[n-1];

  if (sum < largest) {
    cout << largest * 2;
  } else {
    cout << sum + largest;
  }
}

int main() {
  flash;
  solve();
  return 0;
}