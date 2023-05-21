#include "s21_math.h"

long double s21_log(double x) {
  long double result = 0;
  if (x != S21_INF_POS) {
    if (x == 0) {
      result = S21_INF_NEG;
    } else if (x < 0) {
      result = S21_NAN;
    } else {
      int counter_result = 0;
      for (int counter = 0; x >= S21_E; counter++) {
        x /= S21_E;
        if (x < S21_E) {
          counter_result = counter + 1;
        }
      }

      for (int i = 0; i < S21_MAXSTEP; i++) {
        long double coef = (x - s21_exp(result)) / (x + s21_exp(result));
        result = result + 2 * coef;
      }
      result += counter_result;
    }
  } else {
    result = x;
  }

  return result;
}