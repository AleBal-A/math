#include "s21_math.h"

long double s21_floor(double x) {
  if (x != x) {
    ;
  } else if (x != S21_INF_POS && x != S21_INF_NEG) {
    long long buffer =
        (long long)x;  // long long отбрасывает дробную часть числа x
    long double result = buffer;

    if (x <= 0 && buffer != x) result = (long double)((long long)x - 1);

    x = result;
  }
  return x;
}