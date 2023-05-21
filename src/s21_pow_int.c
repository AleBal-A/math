#include "s21_math.h"

long double s21_pow_int(double base, int exp) {
  long double result = 1.0;
  if (exp != 0) {
    if (exp > 0) {
      for (int i = 0; i < (long double)exp; i++) {
        result *= base;
      }
    } else {
      exp = exp * (-1);
      for (int i = 0; i < (long double)exp; i++) {
        result /= base;
      }
    }
  }
  return result;
}