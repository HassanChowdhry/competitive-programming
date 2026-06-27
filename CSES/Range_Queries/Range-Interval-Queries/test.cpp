// GCC pragmas to instruct the compiler to vectorize loops and optimize aggressively 
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 200005;
// log2(200000) is ~17.6, so 20 levels is more than enough
const int MAX_DEPTH = 20;

int arr[MAXN];
int tree[MAX_DEPTH][MAXN];

// Build is identical to standard merge sort, but we save the state at each depth
void build(int depth, int L, int R) {
    if (L == R) {
        tree[depth][L] = arr[L];
        return;
    }
    
    int mid = L + (R - L) / 2;
    build(depth + 1, L, mid);
    build(depth + 1, mid + 1, R);
    
    // Merge the two sorted halves from the level below into the current level
    int p1 = L, p2 = mid + 1;
    int p = L;
    
    while (p1 <= mid && p2 <= R) {
        if (tree[depth + 1][p1] < tree[depth + 1][p2]) {
            tree[depth][p++] = tree[depth + 1][p1++];
        } else {
            tree[depth][p++] = tree[depth + 1][p2++];
        }
    }
    
    // Copy remaining elements
    while (p1 <= mid) tree[depth][p++] = tree[depth + 1][p1++];
    while (p2 <= R)   tree[depth][p++] = tree[depth + 1][p2++];
}

// Query using pointers on the static array
int query(int depth, int L, int R, int qL, int qR, int val_min, int val_max) {
    // Completely outside query range
    if (L > qR || R < qL) {
        return 0;
    }
    
    // Completely inside query range
    if (L >= qL && R <= qR) {
        // Binary search using pointers instead of iterators
        auto start_ptr = tree[depth] + L;
        auto end_ptr = tree[depth] + R + 1;
        
        auto it1 = lower_bound(start_ptr, end_ptr, val_min);
        auto it2 = upper_bound(start_ptr, end_ptr, val_max);
        
        return it2 - it1;
    }
    
    // Partially inside, recurse to children
    int mid = L + (R - L) / 2;
    return query(depth + 1, L, mid, qL, qR, val_min, val_max) + 
           query(depth + 1, mid + 1, R, qL, qR, val_min, val_max);
}

int main() {
    // Fast I/O is absolutely mandatory
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    if (!(cin >> n >> q)) return 0;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    build(0, 1, n);

    for (int i = 0; i < q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << query(0, 1, n, a, b, c, d) << "\n";
    }

    return 0;
}