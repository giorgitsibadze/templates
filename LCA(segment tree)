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
const int MAXN = 4000;
 
int n;
vector<int> G[MAXN + 1];
vector<int> eu;
int used[MAXN + 1];
int depth[MAXN + 1];
vector<int> height;
int t[4 * MAXN];
 
void build(int v, int tl, int tr) {
    if(tl == tr) {
        t[v] = tl;
        return;
    }
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    if(height[t[2 * v]] < height[t[2 * v + 1]])t[v] = t[2 * v];
    else t[v] = t[2 * v + 1];
}
 
int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) return -1;
    if (tl == l && tr == r) return t[v];
    int tm = (tl + tr) / 2;
    int left = sum(2 * v, tl, tm, l, min(r, tm));
    int right = sum(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
    if (left == -1) return right;
    if (right == -1) return left;
    return (height[left] < height[right]) ? left : right;
}
 
void DFS(int v) {
    used[v] = 1;
    eu.pb(v);
    for(int i = 0; i < G[v].size(); i++) {
        int x = G[v][i];
        if(used[x] == 0) {
            depth[x] = depth[v] + 1;
            DFS(x);
            eu.pb(v);
        }
    }
}
 
void solve() {
    cin >> n;
    int m = n - 1;
    while(m--) {
        int x, y;
        cin >> x >> y;
        G[x].pb(y);
        G[y].pb(x);
    }
    DFS(1);
    for(int i = 0; i < eu.size(); i++) {
        height.pb(depth[eu[i]]);
    }
    height.pb(inf);
    vector<int> d(n + 1, 0);
    for(int i = 0; i < eu.size(); i++) {
        if(d[eu[i]] == 0)d[eu[i]] = i;
    }
    build(1, 0, eu.size() - 1);
    int q; cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        cout << eu[sum(1, 0, eu.size() - 1, d[l], d[r])] << '\n';
    }
    eu.resize(0);
    height.resize(0);
    for(int i = 1; i <= n; i++) {
        G[i].resize(0);
        used[i] = 0;
        depth[i] = 0;
    }
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
} 
