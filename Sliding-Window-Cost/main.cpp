#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL);
#define loop(n) for(int i=0;i<n;++i)
#define loopx(x, n) for(int i=x;i<n;++i)
#define input(arr,n);for(int i=0;i<n;++i)cin>>arr[i];
#define ln "\n";

void solve() {
  int n, k; cin >> n >> k;
  vector<int> nums(n, 0), res; input(nums, n);
  multiset<int> high, low;
  int low_sum = 0, high_sum = 0, median;
  loop(k) {
    high.insert(nums[i]); high_sum += nums[i];

    if ((int) high.size() - (int) low.size() > 1) {
      auto it = --high.end(); 
      low.insert(*it); high.erase(it);
      low_sum += (*it); high_sum -= (*it);
    }
  }
  median = *(--high.end());
  res.pb(median);

  loopx(k, n) {
    int rem = nums[i - k];
    if (low.count(rem)) {
      low.erase(rem); low_sum -= rem;
      if ((int) high.size() - (int) low.size() > 1) {
        auto it = --high.end(); 
        low.insert(*it); high.erase(it);
        low_sum += (*it); high_sum -= (*it);
      }
    } else if (high.count(rem)) {
      high.erase(rem); high_sum -= rem;
      if ((int) low.size() - (int) high.size() >= 1) {
        auto it = low.begin();
        high.insert(*it); low.erase(it);
        high_sum += (*it); low_sum -= (*it);
      }
    }

    high.insert(nums[i]); high_sum += nums[i];

    if ((int) high.size() - (int) low.size() > 1) {
      auto it = --high.end(); 
      low.insert(*it); high.erase(it);
      low_sum += (*it); high_sum -= (*it);
    }

      for (auto it = high.begin(); it != high.end(); ++it) {
        cout << *it << " ";
      } cout << ln;

      for (auto it = low.begin(); it != low.end(); ++it) {
        cout << *it << " ";
      } cout << ln;

    median = *(--high.end());
    res.pb(median);
  }

  loop((int) res.size()) {
    cout << res[i] << " ";
  }

}

int main() {
  flash;
  solve();
  return 0;
}