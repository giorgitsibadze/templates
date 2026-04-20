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

const int maxN = 1e4 + 25;
const ll big_inf = 1e18;
const int inf = 1e9;
const int mod = 1e9 + 7;
const int weirdMod = 998244353;

vector<int> G[maxN];
int t_in[maxN], t_out[maxN];
int up[maxN][20];
int cnt;

void DFS(int v, int par) {
    t_in[v] = ++cnt;
    up[v][0] = par;
    for(int i = 1; i < 20; i++) {
        up[v][i] = up[up[v][i - 1]][i - 1];
    }
    for(auto x : G[v]) {
        if(x != par) {
            DFS(x, v);
        }
    }
    t_out[v] = ++cnt;
}

bool is_ancestor(int x, int y) {
    return t_in[x] <= t_in[y] and t_out[x] >= t_out[y];
}

int lca(int x, int y) {
    if(is_ancestor(x, y)) {
        return x;
    }
    if(is_ancestor(y, x)) {
        return y;
    }
    for(int i = 19; i >= 0; i--) {
        if(!is_ancestor(up[x][i], y)) {
            x = up[x][i];
        }
    }
    return up[x][0];
}

void solve() {
    int n;
    cin >> n;
    int m = n - 1;
    while(m--) {
        int x, y;
        cin >> x >> y;
        G[x].pb(y);
        G[y].pb(x);
    }
    DFS(1, 1);
    int x, y;
    cin >> x >> y;
    cout << lca(x, y);
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
