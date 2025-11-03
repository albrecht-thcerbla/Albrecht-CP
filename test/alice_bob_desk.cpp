#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define ll long long

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int n, k, p, q; cin >> n >> k >> p >> q;
  ll idx = (p - 1) * 2 + q;
  ll front = idx - k;
  ll behind = idx + k;
  ll u1 = -1, v1 = -1; 
  ll u2 = -1, v2 = -1; 
  if (front > 0) {
    u1 = (front + 1) / 2;
    v1 = front - (u1 - 1) * 2;
  }
  if (behind <= n) {
    u2 = (behind + 1) / 2;
    v2 = behind - (u2 - 1) * 2;
  }
  ll left, right;
  if (u1 == -1 && u2 == -1) cout << -1 << '\n';
  else if (u1 != -1 && u2 == -1) left = u1, right = v1;
  else if (u1 == -1 && u2 != -1) left = u2, right = v2;
  else {
    ll dist_front = p - u1;
    ll dist_behind = u2 - p;
    if (dist_front <= dist_behind) left = u1, right = v1;
    else left = u2, right = v2;
  }
  if (left != -1) cout << left << " " << right << '\n';
  return 0;
}