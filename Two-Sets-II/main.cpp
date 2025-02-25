#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)
#define rep(i,n) for(int i=0;i<n;++i)
#define input(arr,n);for(int i=0;i<n;++i)cin>>arr[i]
#define ln "\n"
int MOD=1000000007;

void solve() {
  int n; cin >> n;
  int total = n * (n + 1) / 2;
  vector<vector<int>> dp(n+1, vector<int>(total+1, 0));

}

int main() {
  flash;
  solve();
  return 0;
}