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
  vector<int> lis;
  
  // LIS
  loop(n) {
    int num; cin >> num;
    if (lis.empty() || num > lis[lis.size() - 1]) {
      lis.pb(num);
    } else {
      auto it = lower_bound(lis.begin(), lis.end(), num) - lis.begin();
      lis[it] = num;
    }
  }
  cout << lis.size();
}