#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  int idx = 1;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j <= idx; j++) {
      cout << j << " ";
    }
    idx += 2;
    cout << '\n';
  }
  return 0;
}