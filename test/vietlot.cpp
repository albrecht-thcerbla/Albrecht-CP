#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

/**
 * Nhap ket qua trung thuong so xo (6 so ngau nhien trong doan [1; 45])
 * Co N lan thu nghiem, moi lan:
 *   Check xem trung so ko (co thi trung giai gi?)
 *   Xac dinh ty le % giua tien trung so va tien bo ra mua ve so
 *   1 ve = 10k
 *   giong 3 so => trung 30k
 *   giong 4 so => trung 300k
 *   giong 5 so => trung 10 000k
 *   giong 6 so => 12 000 000k
 **/

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  cout << "Nhap 6 so: ";
  vector<int> num(6);
  for (int i = 0; i < 6; i++) cin >> num[i];
  cout << "Nhap so lan mo phong: ";
  int n; cin >> n;
  set<int> se(all(num));

  int64_t price = 10, three = 30, four = 300, five = 10000, six = 12000000;

  int64_t cnt3 = 0, cnt4 = 0, cnt5 = 0, cnt6 = 0, sum = 0;

  vector<int> v(45);
  for (int i = 0; i < 45; i++) v[i] = i + 1;

  random_device rd;
  mt19937 gen(rd());

  for (int i = 0; i < n; i++) {
    shuffle(all(v), gen);
    int won = 0;
    for (int j = 0; j < 6; j++) if (se.count(v[j])) ++won;
    if (won == 3) ++cnt3, sum += three;
    if (won == 4) ++cnt4, sum += four;
    if (won == 5) ++cnt5, sum += five;
    if (won == 6) ++cnt6, sum += six;
  }
  int64_t sum_price = n * price;
  double tile = (double)sum / sum_price * 100.0;
  cout << "Ket qua sau " << n << " lan mo phong:" << '\n';
  cout << "Trung 3 so: " << cnt3 << " lan" << '\n';
  cout << "Trung 4 so: " << cnt4 << " lan" << '\n';
  cout << "Trung 5 so: " << cnt5 << " lan" << '\n';
  cout << "Trung 6 so: " << cnt6 << " lan" << '\n';
  cout << "Tong tien mua ve so: " << sum_price << "K" << '\n';
  cout << fixed << setprecision(6);
  cout << "Ty le phan tram giua tien trung va tien bo ra mua ve so: " << tile << " %" << '\n';
  cout << "Trung binh moi ve nhan duoc: " << (double)sum / n << "K" << '\n';
 
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}
