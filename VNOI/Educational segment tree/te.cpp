#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int MOD = 1007050321;

int pow2[N]; 

struct Node {
    int val, len;
};

int n, q;
string s;
Node tree[4 * N];

void build(int id, int l, int r) {
    if (l == r) {
        tree[id].val = s[l - 1] - '0';
        tree[id].len = 1;
        return;
    }
    int m = (l + r) / 2;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
    Node left = tree[id * 2], right = tree[id * 2 + 1];
    tree[id].val = (1LL * left.val * pow2[right.len] + right.val) % MOD;
    tree[id].len = left.len + right.len;
}

void update(int id, int l, int r, int pos) {
    if (l == r) {
        tree[id].val = 0;
        tree[id].len = 0;
        return;
    }
    int m = (l + r) / 2;
    if (pos <= m) update(id * 2, l, m, pos);
    else update(id * 2 + 1, m + 1, r, pos);
    Node left = tree[id * 2], right = tree[id * 2 + 1];
    tree[id].val = (1LL * left.val * pow2[right.len] + right.val) % MOD;
    tree[id].len = left.len + right.len;
}

pair<int, int> query(int id, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) return {0, 0};
    if (ql <= l && r <= qr) return {tree[id].val, tree[id].len};
    int m = (l + r) / 2;
    auto left = query(id * 2, l, m, ql, qr);
    auto right = query(id * 2 + 1, m + 1, r, ql, qr);
    int val = (1LL * left.first * pow2[right.second] + right.first) % MOD;
    int len = left.second + right.second;
    return {val, len};
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    cin >> s;
    n = s.size();

    pow2[0] = 1;
    for (int i = 1; i <= n; i++)
        pow2[i] = (2LL * pow2[i - 1]) % MOD;

    build(1, 1, n);

    cin >> q;
    vector<int> pos; 
    for (int i = 1; i <= n; i++) pos.push_back(i);

    while (q--) {
        string type;
        cin >> type;
        if (type == "-") {
            int p;
            cin >> p;
            --p;
            int real_pos = pos[p];
            update(1, 1, n, real_pos);
            pos.erase(pos.begin() + p);
        } else {
            int l, r;
            cin >> l >> r;
            --l; --r;
            int pl = pos[l];
            int pr = pos[r];
            cout << query(1, 1, n, pl, pr).first << '\n';
        }
    }

    return 0;
}
