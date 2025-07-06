#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main() {
  int n; string input;
  cin >> input; n = input.size();

  int l = 0, r = 0, res = 0;
  while (r < n) {
    if (input[l] == input[r])
      { ++r; }
    else
      { ++l; }
    
    res = max(res, r - l);
  }

  cout << res;
}