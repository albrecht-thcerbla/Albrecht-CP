#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < n; j++) {
      cout << "#";
    }
    cout << '\n';
  }
  return 0;
}