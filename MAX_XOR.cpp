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

struct node {
    int cnt;
    node *g[2];
};

string binaryshigadaiyvanerogorckargibiwi(int x) {
    string s;
    while(x > 0) {
        s += to_string(x % 2);
        x /= 2;
    }
    while(s.size() < 32) {
        s += "0";
    }
    reverse(s.begin(), s.end());
    return s;
}

void make(node *root, string s) {
    for(int i = 0; i < s.size(); i++) {
        int k = s[i] - '0';
        if(root->g[k] == NULL) {
            root->g[k] = new node();
        }
        root = root->g[k];
    }
}

int findans(node *root, string s) {
    int i = 0;
    string str;
    for(i; i < s.size(); i++) {
        int k = s[i] - '0';
        if(root->g[1 - k] != NULL) {
            str += "1";
            root = root->g[1 - k];
        }
        else if(root->g[k] != NULL) {
            str += "0";
            root = root->g[k];
        }
        else break;
    }
    for(i; i < s.size(); i++) {
        str += s[i];
    }
    int ans = 0;
    reverse(str.begin(), str.end());
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == '1') {
            ans += (1 << i);
        }
    }
    return ans;
}

void solve() {
    node *root = new node();
    int n;
    cin >> n;
    int a[n + 1];
    string str[n + 1];
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        string s = binaryshigadaiyvanerogorckargibiwi(a[i]);
        str[i] = s;
        make(root, s);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, findans(root, str[i]));
    }
    cout << ans;
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
