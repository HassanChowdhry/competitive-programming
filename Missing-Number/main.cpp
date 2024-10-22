#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;

int main() {
  ll n; cin >> n;
  ll sum = (n * (n + 1)) / 2;
  int num;
  for (int i = 0; i < n-1; ++i)
    { cin >> num; sum -= num; }
  
  cout << sum;
}