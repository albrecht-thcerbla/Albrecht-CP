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
  int n; cin >> n;
  vector<char> v(n);
  int cnt = 0;
  for (int i = 0; i < n; i++) cin >> v[i];
  for (int i = 0; i < n; i++) if (i % 2 == 0 && v[i] == '2' || v[i] == '8' || v[i] == 't' || v[i] == 'e' || v[i] == 'c' || v[i] == 'h') if (cnt == 6) return cout << "28TECH" << '\n', 0;
  cout << "HCET82" << '\n';
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}