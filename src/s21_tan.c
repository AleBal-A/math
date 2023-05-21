#include "s21_math.h"

long double s21_tan(double x) {
  long double res = 0.0;
  long double cos = s21_cos(x);

  if (cos != 0) {
    res = s21_sin(x) / cos;
  } else {
    res = S21_NAN;
  }
  return res;
}
