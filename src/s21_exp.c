#include "s21_math.h"

long double s21_exp(double x) {
  long double series = 1;
  if (x != S21_INF_NEG) {
    long double add_value = 1;

    long double i = 1;
    while (s21_fabs(add_value) > S21_LDBL_EPSILON) {
      add_value *= x / i;
      i += 1;
      series += add_value;
      if (series > S21_LDBL_MAX) {
        series = S21_INF_POS;
        break;
      }
    }
  } else {
    series = 0.0;
  }
  return series;
}