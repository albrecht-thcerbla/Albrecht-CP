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
  int tt; cin >> tt;
  while (tt--) {
    string s; cin >> s;
    bool ok = false;
    if (s == "abc") ok = true;
    string tmp = s;
    swap(tmp[0], tmp[1]);
    if (tmp == "abc") ok = true;
    tmp = s;
    swap(tmp[1], tmp[2]);
    if (tmp == "abc") ok = true;
    tmp = s;
    swap(tmp[0], tmp[2]);
    if (tmp == "abc") ok = true;
    cout << (ok ? "YES" : "NO") << '\n';
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}

