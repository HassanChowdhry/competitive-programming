#include <bits/stdc++.h>
using namespace std;

#define ll long long

void generator(long long x, long long a, long long b, long long c, long long n, vector<long long>& nums) {
  nums[1] = x;
  for (long long i = 2LL; i <= n; ++i) nums[i] = (a * nums[i-1LL] + b) % c;
}

void solve() {
    long long n, k; cin >> n >> k;
    long long x, a, b, c; cin >> x >> a >> b >> c;
    
    vector<long long> v(n + 1LL); generator(x, a, b, c, n, v);

    long long ans = 0;

    vector<long long> p(n + 5LL), s(n + 5LL), part(n + 5LL);

    for (long long i = 1; i <= n; i+=k) {
      long long m = min(n, i + k - 1);

      p[i] = v[i];
      part[i] = m + 1LL;
      for (long long j = i + 1LL; j <= m; ++j) {
        p[j] = p[j - 1] | v[j];
        part[j] = m + 1;
      }

      s[m] = v[m];
      for (long long j = m - 1LL; j >= i; --j) {
        s[j] = s[j + 1LL] | v[j];
      }
    }

    long long res;
    for (long long i = 1LL; i <= n - k + 1LL; ++i) {
      if (part[i] >= n + 1) {
        res = s[i];
      } else {
        long long left = ( k - (part[i] - i));
        long long nxt = part[i] + left - 1LL;
        if (left == 0LL) {
          res = s[i];
        } else {
          res = s[i] | p[nxt];
          // cout << i << " " << s[i] << "\n";
          // cout << nxt << " " << p[nxt] << "\n";
        }
        // cout << " \n";
      }

      ans ^= res;


      // cout << res << " ";
    }

    cout << ans;
}


int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    solve();
    return 0;
}