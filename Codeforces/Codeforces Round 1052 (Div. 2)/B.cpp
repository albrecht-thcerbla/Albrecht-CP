#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int tt; cin >> tt;
  while (tt--) {
    int n, m; cin >> n >> m;
    vector<vector<int>> sets(n);
    vector<int> cnt(m + 1, 0);
    for (int i = 0; i < n; i++) {
      int l; cin >> l;
      sets[i].resize(l);
      for (int j = 0; j < l; j++) {
        cin >> sets[i][j];
        cnt[sets[i][j]]++;
      }
    }
    bool ok = true;
    for (int i = 1; i <= m; i++) {
      if (!cnt[i]) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      cout << "NO" << '\n';
      continue;
    }
    vector<bool> ch(n, false);
    for (int i = 0; i < n; i++) {
      for (int x : sets[i]) {
        if (cnt[x] == 1) {
          ch[i] = true;
          break;
        }
      }
    }
    vector<int> cover(m + 1, 0), f_idx;
    int f_set = 0;
    for (int i = 0; i < n; i++) {
      if (ch[i]) for (int x : sets[i]) cover[x] = 1;
      else ++f_set, f_idx.emplace_back(i);
    }
    for (int i = 1; i <= m; i++) {
      if (!cover[i]) {
        bool check = false;
        for (int idx : f_idx) {
          if (binary_search(all(sets[idx]), i)) {
            check = true;
            break;
          }
        }
        if (!check) {
          ok = false;
          break;
        }
      }
    }
    if (!ok) {
      cout << "NO" << '\n';
      continue;
    }
    if (sz(f_idx) >= 2) cout << "YES" << '\n';
    else cout << "NO" << '\n';
  }
  return 0;
}