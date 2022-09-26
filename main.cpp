#include <iostream>

using std::cin, std::cout;

void Fill(long long (*fir)[3000], long long (*sec)[3000], long long fir_l,
          long long sec_l, long long cap) {
  for (long long i = 0; i < fir_l + sec_l; ++i) {
    for (long long j = 0; j < cap; ++j) {
      if (i < fir_l) {
        cin >> fir[i][j];
      } else {
        cin >> sec[i - fir_l][j];
      }
    }
  }
}

long long Max(long long number1, long long number2) {
  if (number1 >= number2) {
    return number1;
  }
  return number2;
}

void Execute(long long (*fir)[3000], long long (*sec)[3000], long long cap) {
  long long q, fir_in, sec_in, l, r;
  cin >> q;
  for (long long i = 0; i < q; ++i) {
    cin >> fir_in >> sec_in;
    l = 0;
    r = cap;
    while (r > l) {
      if (r == 1 + l) {
        if (Max(fir[fir_in - 1][r], sec[sec_in - 1][r]) <
            Max(fir[fir_in - 1][l], sec[sec_in - 1][l])) {
          l = r;
        }
        break;
      }
      if (fir[fir_in - 1][(r + l) / 2] - sec[sec_in - 1][(r + l) / 2] < 0) {
        l = (l + r) / 2;
      } else {
        r = (l + r) / 2;
      }
    }
    cout << l + 1 << "\n";
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long fir_l, sec_l, cap;
  cin >> fir_l >> sec_l >> cap;
  auto* fir = new long long[900][3000];
  auto* sec = new long long[900][3000];
  Fill(fir, sec, fir_l, sec_l, cap);
  Execute(fir, sec, cap);
  delete[] fir;
  delete[] sec;
}
