#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

int64_t solve(string s, int k) {
  int n = sz(s);
  int cnt[26] = {0};
  int diff = 0, l = 0;
  int64_t res = 0;
  for (int r = 0; r < n; r++) {
    if (cnt[s[r] - 'a'] == 0) ++diff;
    cnt[s[r] - 'a']++;

    while (diff > k) {
      cnt[s[l] - 'a']--;
      if (cnt[s[l] - 'a'] == 0) --diff;
      ++l;
    }
    res += (r - l + 1);
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int n, k; cin >> n >> k;
  string s; cin >> s;
  cout << solve(s, 26) - solve(s, k - 1) << '\n';
  return 0;
}
