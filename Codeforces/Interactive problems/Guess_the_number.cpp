// https://codeforces.com/gym/101021/problem/1
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
  int l = 1, r = 1000001;
  while (r - l > 1) {
    int m = (l + r) >> 1;
    cout << m << '\n';
    cout.flush();
    string res; cin >> res;
    if (res == "<") r = m;
    else l = m;
  }
  cout << "! " << l << '\n';
  cout.flush();
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}

