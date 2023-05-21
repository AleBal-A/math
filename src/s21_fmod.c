#include "s21_math.h"

long double s21_fmod(double x, double y) {
  double res = 0.0;
  if ((x == S21_INF_POS || x == S21_INF_NEG) &&
      (y == S21_INF_POS || y == S21_INF_NEG)) {
    res = S21_NAN;
  } else if (y == S21_INF_POS || y == S21_INF_NEG) {
    ;
  } else if (y != 0.0 && !(y != y || x != x)) {
    if (y < 0) y = y * -1;

    int stop = 1;
    double a = 0.0;
    int flag_znak = 0;
    if (y > x) {
      stop = 0;
      res = x;
    }
    if (x < 0) {
      flag_znak = 1;
      x = x * -1;
    }
    for (int i = 0; stop; i++) {
      a = x - y;
      x -= y;
      if (a < y) {
        res = a;
        stop = 0;
      }
    }
    if (flag_znak) res = res * -1;
  } else {
    res = S21_NAN;
  }

  return res;
}