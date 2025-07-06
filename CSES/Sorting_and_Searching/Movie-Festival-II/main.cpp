#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fs first 
#define sc second 
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)
#define rep(i,n) for(int i=0;i<n;++i)
#define input(arr,n);for(int i=0;i<n;++i)cin>>arr[i]
#define ln "\n"

void solve() {
  ll n, k; cin >> n >> k;
  vector<pair<ll, ll>> nums(n, {0, 0});
  rep(i, n)
  cin >> nums[i].fs >> nums[i].sc;
  
  sort(nums.begin(), nums.end());
  multiset<int> pq;
  ll res = 0;

  rep(i, n) {
    while (!pq.empty() && nums[i].fs >= *pq.begin()) {
      pq.erase(pq.begin());
      ++res;
    }

    if ((ll)pq.size() < k) {
      pq.insert(nums[i].sc);
    } else if (!pq.empty() && nums[i].sc < *(--pq.end())) {
      pq.erase(--pq.end()); pq.insert(nums[i].sc);
    }
  }

  res += pq.size();
  
  cout << res;
}

int main() {
  flash;
  solve();
  return 0;
}