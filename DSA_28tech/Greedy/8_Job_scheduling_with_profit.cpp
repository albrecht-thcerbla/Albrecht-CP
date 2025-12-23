#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  pair<int, pair<int, int>> a[n + 1]; // stt - dl - profit
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second.first >> a[i].second.second;
  }
  sort(a, a + n, [](pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    return a.second.first > b.second.first;
  });
  priority_queue<int> pq;
  int cur_day = a[0].second.first; // deadline lon nhat
  int idx = 0;
  long long res = 0;
  while (cur_day >= 1) {
    while (a[idx].second.first == cur_day && idx < n) {
      pq.emplace(a[idx++].second.second);
    }
    if (!pq.empty()) {
      res += pq.top(); pq.pop();
    }
    cur_day--;
  }
  cout << res;
  return 0;
}