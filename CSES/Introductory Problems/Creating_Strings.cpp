#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  string s; cin >> s;
  sort(all(s));
  vector<string> p;
  while (true) {
    p.emplace_back(s);
    if (!next_permutation(all(s))) break;
  }
  cout << sz(p) << '\n';
  for (int i = 0; i < sz(p); i++) cout << p[i] << '\n';
  return 0;
}