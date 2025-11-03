#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

int ans = 0;
string a[8];
bool col[8], dia1[16], dia2[16];

void backtrack(int i) {
  if (i == 8) return void (++ans);
  for (int c = 0; c < 8; c++) {
    if (a[i][c] == '*') continue;
    if (col[c] || dia1[i - c + 7] || dia2[i + c]) continue;
    col[c] = dia1[i - c + 7] = dia2[i + c] = true;
    backtrack(i + 1);
    col[c] = dia1[i - c + 7] = dia2[i + c] = false;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  for (int i = 0; i < 8; i++) cin >> a[i];
  backtrack(0);    
  cout << ans << '\n';
  return 0;
}