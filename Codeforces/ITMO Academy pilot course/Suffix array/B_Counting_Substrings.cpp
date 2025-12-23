/** author : albrecht **/
#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

vector<int> build(string s) {
  int n = sz(s);
  vector<int> sa(n), rk(n), tmp(n);
  iota(all(sa), 0);
  for (int i = 0; i < n; i++) rk[i] = s[i];
  for (int k = 1; k < n; k <<= 1) {
    auto cmp = [&](int i, int j) {
      if (rk[i] != rk[j]) return rk[i] < rk[j];
      int ri = (i + k < n ? rk[i + k] : -1);
      int rj = (j + k < n ? rk[j + k] : -1);
      return ri < rj;
    };
    sort(all(sa), cmp);
    tmp[sa[0]] = 0;
    for (int i = 1; i < n; i++) tmp[sa[i]] = tmp[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
    rk = tmp;
  }
  return sa;
}
int bs(string& t, vector<int>& sa, string& s) {
  int n = sz(t);
  int m = sz(s);
  int l = -1, r = n;
  while (r - l > 1) {
    int mid = (l + r) >> 1;
    if (t.compare(sa[mid], m, s) < 0) l = mid;
    else r = mid;
  }
  int low = l;
  l = -1, r = n;
  while (r - l > 1) {
    int mid = (l + r) >> 1; 
    if (t.compare(sa[mid], m, s) <= 0) l = mid;
    else r = mid;
  }
  int high = l;
  return high - low;
} 
int32_t main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  string t; cin >> t;
  vector<int> sa = build(t);
  int q; cin >> q;
  while (q--) {
    string s; cin >> s;
    cout << bs(t, sa, s) << '\n';
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