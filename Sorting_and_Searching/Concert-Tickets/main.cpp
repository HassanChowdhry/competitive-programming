#include <bits/stdc++.h>
# define ll long long
# define pb push_back
# define all(a) a.begin(),a.end()
# define flash ios_base::sync_with_stdio(false);cin.tie(NULL);
# define test int t;cin>>t;while(t--)
# define loop(n) for(int i=0;i<n;i++)
# define input(arr,n);for(int i=0;i<n;i++)cin>>arr[i];
# define nline "\n"
using namespace std;
int MOD=1000000007;
using namespace std;

int main() {
  int n, p, maxpay; cin >> n >> p;
  multiset<int> tickets;
  loop(n) {
    int m; cin >> m; 
    tickets.insert(m);
  }

  loop(p) {
    cin >> maxpay;
    auto it = tickets.upper_bound(maxpay);
    if (it == tickets.begin()) {
        cout << -1 << nline;
    } else {
        --it;
        cout << *it << nline;
        tickets.erase(it);
    }
  }
}