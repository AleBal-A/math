#include "s21_math.h"

long double s21_sqrt(double x) {
  long double res = 0;

  if (x >= 0) {
    // 1) задаем отрезок, в котором ищем корень
    long double lb = 0;
    long double rb = x > 1 ? x : 1;
    long double resSquared;

    do {
      // 2) ищем центр отрезка
      res = (lb + rb) / 2.0;
      // 3) возводим центр отрезка в квадрат
      resSquared = res * res;

      // 4) если квадрат полученного числа больше x, то свдигаем края отрезка
      if (resSquared > x) {
        rb = res;
      } else {
        lb = res;
      }
    } while (s21_fabs(x - resSquared) > 1e-16);
  } else {
    res = S21_NAN;
  }
  return res;
}