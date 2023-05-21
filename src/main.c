#include <math.h>
#include <stdio.h>

#include "s21_math.h"
#define S21_LDBL_EPSILON 10e-19L
#define S21_LDBL_MAX 1.18973149535723176502e+4932L

long double s21_exp(double x) {
  long double series = 1;
  if (x != -INFINITY) {
    long double add_value = 1;
    long double series = 1;
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

int main() {
  double res = s21_exp(-INFINITY);

  printf("%f\n", res);
  double mat = exp(-INFINITY);

  printf("%f", mat);
  return 0;
}