/** author : albrecht **/
#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

string s;
int n;
vector<int> sa, rk, tmp, lcp;

void build_sa() {
  s += " ";
  n = sz(s);
  sa.resize(n);
  rk.resize(n);
  tmp.resize(n);
  for (int i = 0; i < n; i++) {
    sa[i] = i;
    rk[i] = s[i];
  }
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
}
void kasai() {
  lcp.resize(n - 1); // lcp[i] is defined as Longest Common Prefix of suffix[i] and suffix[i+1]
  vector<int> rk_lcp(n);
  for (int i = 0; i < n; i++) rk_lcp[sa[i]] = i;
  int h = 0;
  for (int i = 0; i < n; i++) {
    if (rk_lcp[i] == 0) continue;
    int j = sa[rk_lcp[i] - 1];
    while (i + h < n && j + h < n && s[i + h] == s[j + h]) ++h;
    lcp[rk_lcp[i] - 1] = h;
    if (h > 0) --h;
  }
}
int32_t main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  cin >> s;
  build_sa();
  kasai();
  for (int i = 0; i < n; i++) cout << sa[i] << " ";
  cout << '\n';
  for (int i = 0; i < n - 1; i++) cout << lcp[i] << " ";
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