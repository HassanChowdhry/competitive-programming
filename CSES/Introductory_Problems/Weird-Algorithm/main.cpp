#include <iostream>
#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;

int main() {
  ll n;
  cin >> n;

  while (n != 1) {
    cout << n << " ";
    if (n % 2)
      { n = ((n * 3) + 1); }
    else 
      { n /= 2; }
  }

  cout << n;
}