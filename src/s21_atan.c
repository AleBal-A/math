#include "s21_math.h"

long double s21_atan(double x) {
  long double res = 0.0;
  // для бесконечности
  if (x == S21_INF_POS) {
    res = S21_PI / 2;

    // для минус бесконечности
  } else if (x == S21_INF_NEG) {
    res = (S21_PI / 2) * -1;
  }
  // для  |x| < 1   =>   -1 < x < 1
  else if (-1 < x && x < 1) {
    for (int i = 0; i < 1000; i++) {
      res += (s21_pow_int(-1, i) * s21_pow_int(x, 1 + 2 * i)) / (1 + 2 * i);
    }
    // для  |x| > 1   =>   -1 > x  ||  x > 1
  } else if (-1 > x || x > 1) {
    for (int i = 0; i < 1000; i++) {
      res += (s21_pow_int(-1, i) * s21_pow_int(x, -1 - 2 * i)) / (1 + 2 * i);
    }
    res = ((S21_PI * s21_fabs(x)) / (2 * x)) - res;

    // для x = -1
  } else if (x == -1) {
    res = (S21_PI / 4) * -1;

    // для x = 1
  } else if (x == 1) {
    res = S21_PI / 4;
  } else {
    res = S21_NAN;
  }

  return res;
}