#include "s21_math.h"

long double s21_asin(double x) {
  long double res = 0.0;
  // для  |x| < 1   =>   -1 < x < 1
  if (-1 < x && x < 1) {
    res = s21_atan(x / s21_sqrt(1 - x * x));
  } else if (x == -1) {
    res = (S21_PI / 2) * -1;
  } else if (x == 1) {
    res = S21_PI / 2;
  } else {
    res = S21_NAN;
  }

  return res;
}
