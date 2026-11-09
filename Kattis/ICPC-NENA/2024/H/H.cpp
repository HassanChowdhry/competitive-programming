#include <bits/stdc++.h>
using namespace std;
long n, X, M; 
string s;
long long primes[] = {2, 3, 5, 7, 11, 13, 17, 19};
long long p[25];
long long mark[10000];
long long xi[25], yi[25], ai[25];

long long extended_gcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long d = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

long long inv(long long a, long long m) {
    long long x, y;
    long long g = extended_gcd(a, m, x, y);
    if (g != 1) return -1;
    return (x % m + m) % m;
}

vector<char> alpha;
void solve() {
    cin >> n >> s;

    char c = 'A';
    for (long long i = 0; i < n; ++i) {
        alpha.push_back(c);
        ++c;
    }

    for (long long i = 2; i <= n; ++i) {
        long long num = i;
        for (long long prime: primes) {
            long long cnt = 0;
            while (num % prime == 0) {
                num /= prime; ++cnt;
            }
            p[prime] = max(p[prime], cnt);
        }
    }

    for (long long i = 0; i < n; ++i) {
        auto it = find(alpha.begin(), alpha.end(), s[i]);
        long long j = it - alpha.begin();
        ai[n - i] = j;
        alpha.erase(it);
    }

    // for (long long i = n; i >= 1; --i) {
    //     cout << i << "  " << ai[i] << "\n";
    // } cout << "\n";

    // m mod n
    // m mod n-1
    // .......
    X = 1;
    for (long long prime : primes) {
        if (p[prime]) {
            long long j = 1;
            for (int e = 1; e <= p[prime]; ++e) j *= prime;
            X *= (j);
            mark[j] = 1;
        }
    }

    // cout << X;
    for (long long i = 1; i <= n; ++i) {
        if (mark[i]) {
            xi[i] = X / i;
            // cout << xi[i] << " ";
            yi[i] = inv(xi[i], i);
        }
    }
    // cout << "\n";

    M = 0;
    for (long i = 1; i <= n; ++i) {
        if (mark[i]) {
            M += (ai[i] % X * xi[i] % X * yi[i] % X);
            M %= X;
        }
    }

    int ok = 1;
    
    for (int i = 1; i <= n; ++i) {
        if (M % i != ai[i]) {
            ok = 0;
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    cout << M << "\n";

}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    solve();
    return 0;
}