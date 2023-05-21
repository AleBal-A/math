#include "s21_math.h"

long double s21_pow(double base, double exp) {
  long double result = 0;

  if (exp == 0) {
    result = 1;
  } else if (base < 0 && exp != exp) {
    return S21_NAN;
  } else {
    result = s21_exp(exp * s21_log(s21_fabs(base)));
  }
  return result;
}
