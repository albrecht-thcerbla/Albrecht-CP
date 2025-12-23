#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
freopen("/home/albrecht/input.inp", "r", stdin);
  freopen("/home/albrecht/output.out", "w", stdout);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n, q;
        cin >> n >> q;
        vector<int> p(n);
        for (int i = 0; i < n; ++i) cin >> p[i];

        vector<pair<int,int>> queries(q);
        for (int i = 0; i < q; ++i) {
            int l, r;
            cin >> l >> r;
            --l; --r;
            queries[i] = {l, r};
        }

        // seen[x] == stamp means value x was seen in current segment
        vector<int> seen(n + 1, -1);
        int stamp = 0;
        int ans = 0;

        for (auto &qr : queries) {
            ++stamp;
            int l = qr.first, r = qr.second;
            // mark values in segment
            for (int i = l; i <= r; ++i) {
                int val = p[i];
                if (val <= n) seen[val] = stamp;
            }
            int mex = 0;
            while (mex <= n && seen[mex] == stamp) ++mex;
            ans = max(ans, mex);
        }

        cout << ans << '\n';
    }

    return 0;
}
