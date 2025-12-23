#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

// De la tam giac thi 3 diem khong duoc thang hang

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int n; cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
  int64_t sum = n * (n - 1) * (n - 2) / 6;
  int straight = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        int64_t x1 = a[i].first, y1 = a[i].second;
        int64_t x2 = a[j].first, y2 = a[j].second;
        int64_t x3 = a[k].first, y3 = a[k].second;
        if ((x2 - x1) * (y3 - y1) == (y2 - y1) * (x3 - x1)) ++straight;
      }
    }
  }
  cout << sum - straight << '\n';
  return 0;
}