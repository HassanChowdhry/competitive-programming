#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main() {
  int n; cin >> n;
  
  if (n <= 3) { 
    if (n == 1)
      { cout << 1; }
    else
      { cout << "NO SOLUTION"; }
    
    return 0; 
  }
  
  string str;

  for (int i = 1; i <= n; ++i) { 
    if (i % 2)
      { str += to_string(i) + " "; }
    else
      { cout << i << " "; }
  }

  cout << str;
}