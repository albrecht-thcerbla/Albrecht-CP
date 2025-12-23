#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;
/**
  Cho mang A gom N phan tu va so nguyen duong K. Tim so luong phan tu lon nhat trong mang sao cho do chenh lech giua 2 pt bat ki trong tap hop chon ra khong vuot qua K.
**/
int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, k; cin >> n >> k;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  int l = 0, r = 0, ans = -1;
  while (r < n) {
    if (a[r] - a[l] > k) {
      while (a[r] - a[l] > k) ++l;
    }
    ans = max(ans, r - l + 1);
    ++r;
  }
  cout << ans << '\n';
  return 0;
}