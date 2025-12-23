/** author : albrecht **/
#include <bits/stdc++.h>
using namespace std;
 
#define all(x) x.begin(), x.end()
 
const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
 
struct Node {
  int64_t sum, pref, suff, ans;
};
int n, m, sz = 1;
vector<int64_t> a;
vector<Node> t;
 
Node calc(Node l, Node r) {
  Node res;
  res.sum = l.sum + r.sum;
  res.pref = max(l.pref, l.sum + r.pref);
  res.suff = max(r.suff, r.sum + l.suff);
  res.ans = max({l.ans, r.ans, l.suff + r.pref});
  return res;
}
void build() {
  for (int i = 0; i < n; i++) t[i + sz] = {a[i], max(0LL, a[i]), max(0LL, a[i]), max(0LL, a[i])};
  for (int i = sz - 1; i > 0; i--) t[i] = calc(t[i << 1], t[i << 1 | 1]);
}
void modify(int p, int64_t val) {
  for (t[p += sz] = {val, max(0LL, val), max(0LL, val), max(0LL, val)}; p > 1; p >>= 1) t[p >> 1] = (p & 1) ? calc(t[p ^ 1], t[p]) : calc(t[p], t[p ^ 1]);
}
int32_t main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);
  cin >> n >> m;
  while (sz < n) sz <<= 1;
  a.resize(sz); t.resize(sz << 1);
  for (int i = 0; i < n; i++) cin >> a[i];
  build();
  cout << t[1].ans << '\n';
  while (m--) {
    int i; cin >> i;
    int64_t val; cin >> val;
    modify(i, val);
    cout << t[1].ans << '\n';
  } 
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