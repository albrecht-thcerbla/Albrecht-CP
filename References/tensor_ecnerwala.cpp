#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

template <typename T, int NDIMS> struct tensor_view {
  static_assert(NDIMS >= 0, "NDIMS must be nonnegative");

protected:
  std::array<int, NDIMS> shape{};
  std::array<int, NDIMS> strides{};
  T* data;

  tensor_view(std::array<int, NDIMS> shape_, std::array<int, NDIMS> strides_, T* data_)
    : shape(shape_), strides(strides_), data(data_) {}

public:
  tensor_view() : shape{0}, strides{0}, data(nullptr) {}

protected:
  int flatten_index(std::array<int, NDIMS> idx) const {
    int res = 0;
    for (int i = 0; i < NDIMS; i++) res += idx[i] * strides[i];
    return res;
  }

  int flatten_index_checked(std::array<int, NDIMS> idx) const {
    int res = 0;
    for (int i = 0; i < NDIMS; i++) {
      assert(0 <= idx[i] && idx[i] < shape[i]);
      res += idx[i] * strides[i];
    }
    return res;
  }

public:
  // truy cập kiểu A[{i,j,k}]
  T& operator[](std::array<int, NDIMS> idx) const { return data[flatten_index(idx)]; }
  T& at(std::array<int, NDIMS> idx) const { return data[flatten_index_checked(idx)]; }

  // truy cập giảm chiều: A[i] -> tensor_view<T, NDIMS-1>
  template <int D = NDIMS>
  typename std::enable_if<(0 < D), tensor_view<T, NDIMS - 1>>::type operator[](int idx) const {
    std::array<int, NDIMS - 1> nshape;
    std::copy(shape.begin() + 1, shape.end(), nshape.begin());
    std::array<int, NDIMS - 1> nstrides;
    std::copy(strides.begin() + 1, strides.end(), nstrides.begin());
    T* ndata = data + (strides[0] * idx);
    return tensor_view<T, NDIMS - 1>(nshape, nstrides, ndata);
  }

  template <int D = NDIMS>
  typename std::enable_if<(0 < D), tensor_view<T, NDIMS - 1>>::type at(int idx) const {
    assert(0 <= idx && idx < shape[0]);
    return operator[](idx);
  }

  // NDIMS == 0 => trả về T&
  template <int D = NDIMS>
  typename std::enable_if<(0 == D), T&>::type operator*() const {
    return *data;
  }

  template <typename U, int D>
  friend struct tensor_view;
  template <typename U, int D>
  friend struct tensor;
};

template <typename T, int NDIMS> struct tensor {
  static_assert(NDIMS >= 0, "NDIMS must be nonnegative");

protected:
  std::array<int, NDIMS> shape{};
  std::array<int, NDIMS> strides{};
  int len{};
  T* data;

public:
  tensor() : shape{0}, strides{0}, len(0), data(nullptr) {}

  explicit tensor(std::array<int, NDIMS> shape_, const T& t = T()) {
    shape = shape_;
    if constexpr (NDIMS > 0) {
      strides[NDIMS - 1] = 1;
      for (int i = NDIMS - 1; i > 0; i--) strides[i - 1] = strides[i] * shape[i];
      len = strides[0] * shape[0];
    } else len = 1;
    data = new T[len];
    std::fill(data, data + len, t);
  }

  tensor(const tensor& o)
    : shape(o.shape), strides(o.strides), len(o.len), data(new T[len]) {
    std::copy(o.data, o.data + len, data);
  }

  tensor& operator=(tensor&& o) noexcept {
    using std::swap;
    swap(shape, o.shape);
    swap(strides, o.strides);
    swap(len, o.len);
    swap(data, o.data);
    return *this;
  }

  tensor(tensor&& o) : tensor() { *this = std::move(o); }
  tensor& operator=(const tensor& o) { return *this = tensor(o); }

  ~tensor() { delete[] data; }

  // ========== tiện ích thêm ==========
  void fill(const T& val) { std::fill(data, data + len, val); }
  T* begin() { return data; }
  T* end() { return data + len; }
  const T* begin() const { return data; }
  const T* end() const { return data + len; }

  // view
  using view_t = tensor_view<T, NDIMS>;
  view_t view() { return tensor_view<T, NDIMS>(shape, strides, data); }
  operator view_t() { return view(); }

  using const_view_t = tensor_view<const T, NDIMS>;
  const_view_t view() const { return tensor_view<const T, NDIMS>(shape, strides, data); }
  operator const_view_t() const { return view(); }

  // truy cập phần tử
  T& operator[](std::array<int, NDIMS> idx) { return view()[idx]; }
  T& at(std::array<int, NDIMS> idx) { return view().at(idx); }
  const T& operator[](std::array<int, NDIMS> idx) const { return view()[idx]; }
  const T& at(std::array<int, NDIMS> idx) const { return view().at(idx); }

  // truy cập giảm chiều
  template <int D = NDIMS>
  typename std::enable_if<(0 < D), tensor_view<T, NDIMS - 1>>::type operator[](int idx) {
    return view()[idx];
  }

  template <int D = NDIMS>
  typename std::enable_if<(0 < D), tensor_view<T, NDIMS - 1>>::type at(int idx) {
    return view().at(idx);
  }

  template <int D = NDIMS>
  typename std::enable_if<(0 < D), tensor_view<const T, NDIMS - 1>>::type operator[](int idx) const {
    return view()[idx];
  }

  template <int D = NDIMS>
  typename std::enable_if<(0 < D), tensor_view<const T, NDIMS - 1>>::type at(int idx) const {
    return view().at(idx);
  }

  // NDIMS == 0
  template <int D = NDIMS>
  typename std::enable_if<(0 == D), T&>::type operator*() { return *view(); }

  template <int D = NDIMS>
  typename std::enable_if<(0 == D), const T&>::type operator*() const { return *view(); }
};

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);

  tensor<int, 3> ts({3, 3, 3});
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        cin >> ts[{i, j, k}];
      }
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        cout << ts[{i, j, k}] << " ";
      }
      cout << '\n';
    }
    cout << '\n';
  }

  
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}