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
#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define ll long long
#define pb push_back
#define popb pop_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define sc second
#define all(x) x.begin(), x.end()

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngl(chrono::steady_clock::now().time_since_epoch().count());

const int maxN = 2 * 1e5;
const ll big_inf = 1e18;
const int inf = 1e9;
const int mod = 1e9 + 7;
const int weirdMod = 998244353;

void solve() {
    int n;
    cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 30; i >= 0; i--) {
        int cnt = 0;
        for(int j = 1; j <= n; j++) {
            if((a[j] & (ans | (1 << i))) == (ans | (1 << i))) {
                cnt++;
            }
        }
        if(cnt >= 2) {
            ans |= (1 << i);
        }
    }
    cout << ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
        cout << '\n';
    }
    return 0;
}
