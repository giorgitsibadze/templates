#pragma GCC optimize("Ofast")
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <queue>
#include <map>
#include <cmath>
#include <iomanip>
#include <stack>
using namespace std;

// #define int long long
#define ll long long
#define pb push_back
#define popb pop_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define sc second

const int mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 2 * 1e5;

int m[100001][20];

void solve() {
    int n;
    cin >> n;
    int f = log2(n);
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        m[i][0] = a[i];
    }
    for(int t = 1; t <= f; t++) {
        for(int i = 0; i < n; i++) {
            if(i + (1 << (t - 1)) < n) {
                m[i][t] = min(m[i][t - 1], m[i + (1 << (t - 1))][t - 1]);
            }
        }
    }
    int q;
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        int x = log2(r - l + 1);
        cout << min(m[l][x], m[r - (1 << x) + 1][x]) << '\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
        cout << '\n';
    }
    return 0;
}
