#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;

int main() {
  int n;
  ll moves = 0, change = 0;
  cin >> n;
  vector<int> nums(n);

  for (int i = 0; i < n; ++i)
    { cin >> nums[i]; }
  
  for (int i = 1; i < n; ++i) { 
    if (nums[i] >= nums[i-1]) continue; 
    
    change = nums[i-1] - nums[i]; 
    nums[i] += change; moves += change;
  }
  
  cout << moves;
}