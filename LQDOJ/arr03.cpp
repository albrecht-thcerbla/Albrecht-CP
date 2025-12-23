#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, k; cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int mn = 1e9;
  vector<int> pos;
  int ptr;
  for (int i = 0; i < n; i++) {
    if (a[i] > k) {
      if (a[i] <= mn) {
        if (a[i] == mn) {
          pos.emplace_back(i + 1);
        }
        mn = a[i];
        ptr = i + 1;
        pos.clear();        
      }
    }
  }
  cout << mn << '\n';
  if (!pos.empty()) {
    for (int i = 0; i < sz(pos); i++) cout << pos[i] << " ";
    return 0;
  }
  cout << ptr;
  return 0;
}