#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

class Process {
public:
  int id, arr, bur, rem, st = -1, fn = 0;
};
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  int n, k; cin >> n >> k;
  vector<Process> p(n);
  for (int i = 0; i < n; i++) cin >> p[i].arr, p[i].id = i + 1;
  for (int i = 0; i < n; i++) cin >> p[i].bur, p[i].rem = p[i].bur;
  vector<int> od(n);
  iota(all(od), 0);
  sort(all(od), [&](int a, int b) {
    return p[a].arr < p[b].arr;
  });
  queue<int> q;
  int times = 0, nxt = 0, done = 0;
  times = p[od[0]].arr;
  while (nxt < n && p[od[nxt]].arr <= times) q.emplace(od[nxt++]);
  while (done < n) {
    if (!sz(q)) {
      times = p[od[nxt]].arr;
      q.emplace(od[nxt++]);
    }
    int i = q.front(); q.pop();
    if (p[i].st == -1) p[i].st = times;
    int res = min(k, p[i].rem);
    p[i].rem -= res;
    times += res;
    while (nxt < n && p[od[nxt]].arr <= times) q.emplace(od[nxt++]);
    if (!p[i].rem) p[i].fn = times, done++;
    else q.emplace(i);
  }
  for (int i = 0; i < n; i++) {
    int x = p[i].fn - p[i].arr;
    int y = x - p[i].bur;
    cout << p[i].id << " " << p[i].arr << " " << p[i].bur << " " << y << " " << x << '\n';
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}

