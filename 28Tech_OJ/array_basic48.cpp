#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int tt; cin >> tt;
  for (int t = 1; t <= tt; t++) {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int curlen = 1, mxlen = 1;
    vector<vector<int>> res;
    vector<int> curseq = {a[0]};
    for (int i = 1; i < n; i++) {
      if (a[i] > a[i - 1]) {
        curseq.emplace_back(a[i]);
        ++curlen;
      } else {
        if (curlen > mxlen) {
          mxlen = curlen;
          res.clear();
          res.emplace_back(curseq);
        } else if (curlen == mxlen) res.emplace_back(curseq);
        curseq = {a[i]};
        curlen = 1;
      }
    }
    if (curlen > mxlen) {
      mxlen = curlen;
      res.clear();
      res.emplace_back(curseq);
    } else if (curlen == mxlen) res.emplace_back(curseq);
    cout << "Test #" << t << " :" << '\n';
    cout << mxlen << '\n';
    for (int i = 0; i < sz(res); i++) {
      for (int j = 0; j < sz(res[i]); j++) {
        cout << res[i][j] << " ";
      }
      cout << '\n';
    }
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}