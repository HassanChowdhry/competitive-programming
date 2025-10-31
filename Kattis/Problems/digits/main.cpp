#include <bits/stdc++.h>
using namespace std;
#define ln "\n"

void solve() {
    string s;
    while (cin >> s && s != "END") {
        long long cnt = 1;
		string x = s;
		while (true) {
			string nxt = to_string(x.size());
			if (nxt == x) { cout << cnt << ln; break; }
			x = nxt;
			++cnt;
		}
    }
}

int main() {
    solve();
    return 0;
}