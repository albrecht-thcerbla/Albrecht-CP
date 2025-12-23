#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
#define int int64_t

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

struct Event { 
  int pos, id, ty;
};
bool cmp(Event a, Event b) {
  if (a.pos != b.pos) return a.pos < b.pos;
  return a.ty > b.ty;
}
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int n; cin >> n;
  vector<array<int, 2>> c(n);
  for (int i = 0; i < n; i++) cin >> c[i][0] >> c[i][1];
  vector<Event> e;
  for (int i = 0; i < n; i++) {
    e.push_back({c[i][0] - c[i][1], i, 1});
    e.push_back({c[i][0] + c[i][1], i, -1});
  }
  sort(all(e), cmp);
  int ans = 1;
  stack<int> st;
  for (int i = 0; i < sz(e); i++) {
    if (e[i].ty == 1) {
      ++ans;
      st.push(e[i].id);
    } else {
      while (sz(st) && st.top() != e[i].id) st.pop();
      if (sz(st)) st.pop();
      if (i + 1 < sz(e) && e[i].pos == e[i + 1].pos) ++ans;
    }
  }
  cout << ans << '\n';  
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}