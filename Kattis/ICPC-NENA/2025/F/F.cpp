#include <bits/stdc++.h>
using namespace std;

void solve() {
  long long n; cin >> n;
  long long i;
  for (long long j = 1; j <= 100000; ++j) {
    if ((j*(j + 1)/ 2) >= n) {
      i = j;
      break;
    }
  }

  // cout << i << " ";
  long long offset = i * ( i - 1 ) / 2;
  // cout <<  << " ";
  long long num = n - offset - 1;
  long long denum = i;

  // cout << num << " " << denum << " ";

  long long gcd = __gcd(denum, num);
  if (gcd != 0) {
    num/=gcd;
    denum/=gcd;
  }

  cout << i << " ";

  if (num == 0) return;
  cout << num << "/" << denum;
}

int main() {
  solve();
  return 0;
}
