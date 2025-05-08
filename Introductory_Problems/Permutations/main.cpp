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

  deque<int> q; q.push_back(2); q.push_back(4); q.push_back(1); q.push_back(3);
  int curr = 5;

  while (curr <= n) {
    if (curr % 2)
      { q.push_back(curr); }
    else
      { q.push_front(curr); }

    ++curr;
  }

  for (int i = 0; i < n; ++i)
    { cout << q.front() << " "; q.pop_front(); }
}