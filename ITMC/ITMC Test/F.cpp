#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  string s; cin >> s;
  set<string> se; se.insert(s);
  deque<string> dq; dq.emplace_back(s);
  while (sz(dq)) {
    string cur = dq.front(); dq.pop_front();
    if (sz(cur) < 2) continue;
    char a = cur[0], b = cur[1];
    string chop = cur.substr(2); // xx0111
    for (int i = 0; i < 2; i++) {
      char c = (i == 0 ? a : b);
      for (int j = 0; j <= sz(chop); j++) {
        string tmp;
        tmp.append(chop.begin(), chop.begin() + j);
        tmp += c;
        tmp.append(chop.begin() + j, chop.end());
        if (se.insert(tmp).second) dq.emplace_back(tmp);
      }
    }
  }
  cout << sz(se) % mod << '\n';
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}