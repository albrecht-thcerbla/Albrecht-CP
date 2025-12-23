/** author : albrecht **/
#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define int int64_t

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

struct Node {
  int w, d, val;
};
int n, m, b, seg;
vector<int> cm;
pair<int, int> c[maxn];
Node a[maxn];

class ST {
public:
  int size;
  vector<int64_t> t, lazy;
  void build(int n, const vector<int>& base) {
    size = n;
    t.assign(n << 1, 0);
    lazy.assign(n, 0);
    for (int i = 0; i < n; i++) t[i + n] = -1 * b * base[i];
    for (int i = n - 1; i > 0; i--) t[i] = max(t[i << 1], t[i << 1 | 1]);
  }
  void apply(int p, int64_t val) {
    t[p] += val;
    if (p < size) lazy[p] += val; 
  }
  void push_down(int p) {
    if (size == 0) return;
    int h = 32 - __builtin_clz(size);
    for (int s = h; s; s--) {
      int i = p >> s;
      if (lazy[i]) {
        apply(i << 1, lazy[i]);
        apply(i << 1 | 1, lazy[i]);
        lazy[i] = 0;
      }
    }
  }
  void push_up(int p) {
    while (p > 1) {
      p >>= 1;
      t[p] = max(t[p << 1], t[p << 1 | 1]) + lazy[p];
    }
  }
  void update(int l, int r, int val) {
    l += size, r += size + 1;
    int ll = l, rr = r - 1;
    push_down(ll);
    push_down(rr);
    for (; l < r; l >>= 1, r >>= 1) {
      if (l & 1) apply(l++, val);
      if (r & 1) apply(--r, val);
    }
    push_up(ll);
    push_up(rr);
  }
  int get(int l, int r) {
    l += size, r += size + 1;
    push_down(l);
    push_down(r - 1);
    int res = -1e9;
    for (; l < r; l >>= 1, r >>= 1) {
      if (l & 1) res = max(res, t[l++]);
      if (r & 1) res = max(res, t[--r]);
    }
    return res;
  }
};
int32_t main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  // freopen("fishing.inp", "r", stdin);
  // freopen("fishing.out", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].w >> a[i].d >> a[i].val;
    cm.emplace_back(a[i].d);
  }
  cin >> m;
  for (int i = 1; i <= m; i++) cin >> c[i].first >> c[i].second;
  cin >> b;
  sort(a + 1, a + n + 1, [](const Node& x, const Node& y) {
    return x.w < y.w;
  });
  sort(all(cm));
  cm.erase(unique(all(cm)), cm.end());
  for (int i = 1; i <= n; i++) a[i].d = lower_bound(all(cm), a[i].d) - cm.begin();
  ST t;
  t.build(sz(cm), cm);
  sort(c + 1, c + m + 1);
  int tmp = 1;
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    while (tmp <= n && a[tmp].w <= c[i].first) {
      t.update(a[tmp].d, sz(cm) - 1, a[tmp].val);
      ++tmp;
    }
    ans = max(ans, -1 * c[i].second + t.get(0, sz(cm) - 1));
  }
  cout << ans << '\n';
  return 0;
}

/**
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡀⣀⠀⠀⠀⠀⣰⠃⠀⢀⠎⠀⠀⢀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⢱⡀⠙⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⡠⠠⢤⠃⠀⠀⡃⠀⠀⠰⠮⡆⡠⡽⣀⠀⠀⢸⡟⡿⠉⢁⠂⠀⠀⠀⠈⠉⢻⡀⢄⣀⢠⢄⣏⢴⠳⢣⠀⠀⠀⠀⠀⠀⢀⣀⡀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠐⡄⠀⠀⢃⠀⠴⠡⢄⢀⢃⡰⢔⢉⣠⡯⣠⢷⣾⣴⡑⣅⢸⡟⢱⠘⣀⡍⡆⠞⣧⢎⡹⣆⢊⢀⡈⢧⢰⠆⡰⠂⠙⠲⣴⠃⠀⠀⠑⡄
⠀⠀⠀⠀⠀⠀⠀⠀⢀⠜⠒⠀⠂⠀⡀⠀⢈⢯⢳⢛⣵⡿⠁⣰⡏⢱⢧⣿⢉⡇⣾⢡⡸⠈⢹⣵⢸⠸⣹⡌⠑⢻⡆⢪⡜⢫⢏⢻⠃⠀⠀⠀⠈⡀⠀⠀⣠⢃
⠀⠀⠀⠀⠀⢀⣀⠀⠸⡀⢀⡠⡅⠀⢹⠁⢉⢗⢯⣾⡿⠁⣼⡟⠀⣼⣸⢉⢸⡇⢿⢸⠀⡇⢸⡆⡏⣣⢳⣣⢢⠀⣿⡌⣿⣴⡹⣎⣦⡀⠀⠀⠨⠤⠀⠀⠀⠀    cake! cake! cake! x3.14
⠀⠀⠀⠀⣅⡕⠐⡆⠀⠀⠁⠀⠙⠓⢁⠴⣩⢣⣿⣿⠃⣼⣿⢁⢰⡇⡟⢹⣿⡇⡘⡘⣇⢳⡀⡜⣼⣏⢂⢻⡞⣧⠸⣷⠸⣿⣿⡌⣇⠉⢙⠃⠀⠀⠈⣦⣀⣀
⠀⠀⠀⠀⠀⠒⠊⠀⠀⠀⠀⣀⣤⠺⠕⠈⢇⣏⣿⡏⣴⣿⠃⡜⡘⢴⡗⠚⣿⠸⡇⢡⣋⠌⡥⣡⠐⣿⡠⢧⡱⣻⣆⣿⡇⢻⣷⣷⢰⡑⢔⠧⣀⣀⡠⠃⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠀⠀⠻⠿⠘⢸⢸⡿⢀⣿⠋⡰⢁⢃⣨⣧⣀⣙⡤⠀⠀⠉⠈⠁⠨⢥⣤⣥⡄⢈⢣⢿⣿⣿⠸⣿⣸⣇⡎⠙⠳⢄⡀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⣀⡀⠀⠀⠀⠀⠀⢠⢸⢸⡇⡸⢃⣴⠃⡼⠻⠛⠻⠋⠛⠛⠀⠀⠀⠀⠀⠘⠛⠉⠋⠛⠻⢯⣮⢻⣿⡆⣿⡏⣿⡧⡀⢠⣀⠂⠁⠀⠀⠀
⠀⠀⠀⠀⢠⢄⡀⠀⠛⠧⣈⠤⡄⢀⡴⠛⣼⠸⡇⣧⣾⡟⡜⠀⠀⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣇⢡⡻⡇⡏⢸⣿⠑⢌⠺⠢⠋⠀⠀⠀⡠
⠀⠀⠀⠨⡝⠾⢔⠀⠀⠱⡱⣙⠵⢉⠠⠊⠈⣧⠇⣿⣿⡎⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⣼⡜⡇⢁⡾⠇⠀⠑⠑⢔⢄⠀⡦⠠⢇
⠀⠀⠀⠀⠑⠊⠊⠀⠀⠀⢠⡪⠐⠁⠀⠀⡼⡁⣿⣟⣿⣿⡀⠀⠀⠀⠀⠀⠀⠐⠖⠠⠤⠄⠀⠆⠀⠀⠀⠀⠀⠠⢎⣽⣥⢡⠎⡧⡘⡀⢪⣛⠀⠵⣎⢆⣀⣀
⠀⠀⠀⠀⠀⠀⢀⡤⢄⣰⡏⠀⠀⠀⢀⠞⡕⢡⠹⠇⣧⢟⣿⣦⣀⠀⠀⠀⠀⠀⠀⠀⠀⡀⡤⡠⡀⠀⠀⠀⢀⣤⣾⠇⠋⠑⠀⣇⠱⡐⡄⠈⠀⠈⣾⠀⢰⠁
⠀⠀⡠⠒⠒⠢⢏⠀⠀⠸⣿⣆⣀⠔⣡⠎⠀⣜⣇⠀⢉⢾⢚⢿⣿⣿⣶⣶⡶⠂⠤⠀⠘⠃⠰⠈⠌⢲⣾⣿⣿⣿⠏⠶⢀⡇⠠⣿⣆⠘⢮⡦⡀⢰⣿⠀⠉⠕
⠀⠀⠁⠀⠀⠀⡠⠄⠀⠐⡻⣟⣵⡿⢣⢂⣼⣻⣿⠀⢡⠃⠣⢣⡻⡟⠛⠉⣀⠑⠠⠀⣸⠘⡀⢃⠈⠀⢊⠿⢿⠏⠮⢫⣼⡰⢳⣿⣿⣧⠈⢪⣪⡙⢇⠀⠀⠀
⠀⠀⠓⠤⢤⠄⠑⢀⡴⠝⠈⣽⡜⢠⢢⣾⣿⣧⠟⢃⠀⠫⣶⡨⡎⢕⡄⠀⠁⠀⠀⠀⠀⠆⠀⠀⠀⠀⠈⠚⣎⡜⣠⣷⡏⡝⢆⢿⣿⣿⣷⣏⠻⡋⢂⢗⢄⠀
⠀⠀⠀⠈⣸⡀⢠⡿⢸⠓⠚⣙⢣⣳⣿⣿⣿⣇⠀⠈⡄⢀⢹⣿⠃⠈⡶⠀⢰⢀⠠⠄⠀⠸⡀⠀⠀⠀⠀⠀⢋⢟⣿⡿⢀⡟⡜⠀⢿⣿⢿⣿⣆⢚⡄⢡⠱⣱⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀

**/
