#include <bits/stdc++.h>
using namespace std;
#define ln "\n"

int h[200005];
int d[500005];
void solve() {
    int N, H; cin >> N >> H;
    for (int i =0; i < N; ++i) { 
        cin >> h[i];
        if (i % 2) { h[i]=H-h[i]; ++d[h[i]]; --d[H]; }
        else { ++d[0]; --d[h[i]]; }
    }
    
    for (int i = 1; i <= H; ++i) {
        d[i] += d[i-1];
    }
    int mn = N, cnt = 1;  
    for (int i = 0; i < H; ++i) {
        if (d[i] < mn) {
          mn = d[i];
          cnt = 1;
        } else if (d[i] == mn) ++cnt;
    }

	cout << mn << " " << cnt;
}   

int main() {
    solve();
    return 0;
}