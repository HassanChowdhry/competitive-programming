#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fs first 
#define sc second 
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)
#define rep(i,n) for(int i=0;i<n;++i)
#define repx(i,x,n) for(int i=x;i<n;++i)
#define input(arr,n);for(int i=0;i<n;++i)cin>>arr[i]
#define ln "\n"

void solve() {
  int n; cin >> n;
  vector<int> nums(n), res(n, 0); input(nums, n);
  stack<int> stack; stack.push(0);

  repx(i, 1, n) {
    while (!stack.empty() && nums[stack.top()] >= nums[i]) {
      stack.pop();
    }

    if (stack.empty()) 
      { stack.push(i); continue; }
    
    res[i] = stack.top() + 1;
    stack.push(i);
  }

  rep(i, n) 
    cout << res[i] << " "; 
}

int main() {
  flash;
  solve();
  return 0;
}