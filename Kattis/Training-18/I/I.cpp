#include <bits/stdc++.h>
using namespace std;

void LSH() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

long long n,k,x;
void solve() {
    cin >> n >> k;
    vector<int> vt;
    for ( int i = 1 ; i <= n ; ++i ) {
        int l = 0;
        int r = vt.size() - 1;
        int pos = -1;
        int m = vt.size();
        while ( l <= r ) {
            int mid = (l + r)>>1;
            cout<<"? "<<vt[mid]<<" "<<i<<'\n';
            cout.flush();
            cin >> x;
            if ( x == i ) {
                pos = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if ( vt.size() == k ) {
            
            if ( pos != -1 ) {
                vector<int> newVt;
                for ( int j = 1 ; j <= pos ; ++j ) {
                    newVt.push_back(vt[j]);
                }
                newVt.push_back(i);
                for ( int j = pos + 1 ; j < k ; ++j ) {
                    newVt.push_back(vt[j]);
                }
                vt = newVt;
            }
        } else {
            vector<int> newVt;
            if ( pos == -1 ) {
                newVt.push_back(i);
                for ( auto j : vt ) {
                    newVt.push_back(j);
                }
                vt = newVt;
            } else {
                for ( int j = 0 ; j <= pos ; ++j ) {
                    newVt.push_back(vt[j]);
                }
                newVt.push_back(i);
                for ( int j = pos + 1 ; j < m ; ++j ) {
                    newVt.push_back(vt[j]);
                }
                vt = newVt;
            }
        }
    }
    cout<<"! ";
    for ( auto i : vt ) {
        cout<<i<<" ";
    }
    cout<<'\n';
}

int main() {
    LSH();
    solve();
}