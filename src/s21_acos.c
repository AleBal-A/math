#include "s21_math.h"

long double s21_acos(double x) {
  long double res = 0.0;
  if (0 < x && x < 1) {
    res = s21_atan(s21_sqrt(1 - x * x) / x);

  } else if (-1 < x && x < 0) {
    res = s21_atan(s21_sqrt(1 - x * x) / x) + S21_PI;

  } else if (x == -1) {
    res = S21_PI;
  } else if (x == 1) {
    res = 0.0;
  } else if (x == 0) {
    res = S21_PI / 2;
  } else {
    res = S21_NAN;
  }

  return res;
}
