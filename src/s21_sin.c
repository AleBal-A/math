#include "s21_math.h"

long double s21_sin(double x) {
  long double res = 0.0;
  if (x != S21_INF_POS && x != S21_INF_NEG) {
    for (; x < -2 * S21_PI || 2 * S21_PI < x;) {
      if (x > 2 * S21_PI)
        x -= 2 * S21_PI;
      else
        x += 2 * S21_PI;
    }
    for (int i = 0; i < 16; i++) {
      res += (s21_pow_int(-1, i) * s21_pow_int(x, 2 * i + 1)) /
             s21_factorial(2 * i + 1);
    }
  } else {
    res = S21_NAN;
  }
  return res;
}