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

// greedy intervals
int main() {
  int n, l, r; cin >> n;
  vector<pair<ll, ll>> intervals; 
  priority_queue<ll, vector<ll>, greater<ll>> heap;

  loop(n) 
    { cin >> l >> r; intervals.pb({l, r}); } sort(intervals.begin(), intervals.end());

  int res = 1;
  loop(n) {
    while (!heap.empty() && heap.top() < intervals[i].first) 
      { heap.pop(); }

    heap.push(intervals[i].second); res = max(res, (int) heap.size());
  }

  cout << res;
}