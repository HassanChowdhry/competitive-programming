#include <bits/stdc++.h>
# define ll long long
# define pb push_back
# define all(a) a.begin(),a.end()
# define flash ios_base::sync_with_stdio(false);cin.tie(NULL);
# define test int t;cin>>t;while(t--)
# define loop(n) for(int i=0;i<n;++i)
# define input(arr,n);for(int i=0;i<n;++i)cin>>arr[i];
# define nline "\n"
using namespace std;
int MOD=1000000007;

int main() {
  int n; cin >> n;
  vector<int> towers;
  
  // LIS
  loop(n) {
    int num; cin >> num;
    if (towers.empty() || num >= towers[towers.size() - 1]) {
      towers.pb(num);
    } else {
      auto it = upper_bound(towers.begin(), towers.end(), num) - towers.begin();
      towers[it] = num;
    }
  }
  cout << towers.size();
}