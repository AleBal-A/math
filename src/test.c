#include <check.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_math.h"

#define CK_FROK no
#define BUFF_SIZE 512

// ABS
START_TEST(s21_abs_test_1) {
  int a = rand();
  ck_assert_int_eq(abs(-a), s21_abs(-a));
}
END_TEST

START_TEST(s21_abs_test_2) {
  int a = 0;
  ck_assert_int_eq(abs(a), s21_abs(a));
}
END_TEST

START_TEST(s21_abs_test_3) {
  int min = INT_MIN;
  ck_assert_int_eq(abs(min), s21_abs(min));
}
END_TEST

START_TEST(s21_abs_test_4) {
  int max = INT_MAX;
  ck_assert_int_eq(abs(max), s21_abs(max));
}
END_TEST

// FABS
START_TEST(s21_fabs_test_1) {
  double a = rand();
  a = a / RAND_MAX * 10;
  ck_assert_double_eq_tol(fabs(a), s21_fabs(a), ACCURACY);
}
END_TEST

START_TEST(s21_fabs_test_2) {
  double a = 0.0;
  ck_assert_double_eq_tol(fabs(a), s21_fabs(a), ACCURACY);
}
END_TEST

START_TEST(s21_fabs_test_3) {
  double a = NAN;
  ck_assert_double_nan(fabs(a));
  ck_assert_double_nan(s21_fabs(a));
}
END_TEST

START_TEST(s21_fabs_test_4) {
  double a = INFINITY;

  ck_assert_double_infinite(fabs(a));
  ck_assert_double_infinite(s21_fabs(a));
}
END_TEST

START_TEST(s21_fabs_test_5) {
  double a = -INFINITY;

  ck_assert_double_infinite(fabs(a));
  ck_assert_double_infinite(s21_fabs(a));
}
END_TEST

// SQRT
START_TEST(s21_sqrt_test_1) {
  double a = rand();
  a = a / RAND_MAX * 10;
  ck_assert_double_eq_tol(sqrt(a), s21_sqrt(a), ACCURACY);
}
END_TEST

START_TEST(s21_sqrt_test_2) {
  double a = 2.7;
  ck_assert_double_eq_tol(sqrt(a), s21_sqrt(a), ACCURACY);
}
END_TEST

START_TEST(s21_sqrt_test_3) {
  double a = -7.9;
  ck_assert_double_nan(sqrt(a));
  ck_assert_double_nan(s21_sqrt(a));
}
END_TEST

START_TEST(s21_sqrt_test_4) {
  double a = 0.0;
  ck_assert_double_eq_tol(sqrt(a), s21_sqrt(a), ACCURACY);
}
END_TEST

START_TEST(s21_sqrt_test_5) {
  double a = NAN;

  ck_assert_double_nan(sqrt(a));
  ck_assert_double_nan(s21_sqrt(a));
}
END_TEST

START_TEST(s21_sqrt_test_6) {
  double a = INFINITY;

  ck_assert_double_infinite(sqrt(a));
  ck_assert_double_infinite(s21_sqrt(a));
}
END_TEST

START_TEST(s21_sqrt_test_7) {
  double a = -INFINITY;

  ck_assert_double_nan(sqrt(a));
  ck_assert_double_nan(s21_sqrt(a));
}
END_TEST

// FLOOR
START_TEST(s21_floor_test_1) {
  double a = rand();
  a = a / RAND_MAX * 10;
  ck_assert_double_eq_tol(floor(a), s21_floor(a), ACCURACY);
}
END_TEST

START_TEST(s21_floor_test_2) {
  double a = rand();
  a = a / RAND_MAX * (-10);
  ck_assert_double_eq_tol(floor(a), s21_floor(a), ACCURACY);
}
END_TEST

START_TEST(s21_floor_test_3) {
  double a = 0.0;
  ck_assert_double_eq_tol(floor(a), s21_floor(a), ACCURACY);
}
END_TEST

START_TEST(s21_floor_test_4) {
  double a = NAN;
  ck_assert_double_nan(floor(a));
  ck_assert_double_nan(s21_floor(a));
}
END_TEST

START_TEST(s21_floor_test_5) {
  double a = INFINITY;

  ck_assert_double_infinite(floor(a));
  ck_assert_double_infinite(s21_floor(a));
}
END_TEST

START_TEST(s21_floor_test_6) {
  double a = -INFINITY;

  ck_assert_double_infinite(floor(a));
  ck_assert_double_infinite(s21_floor(a));
}
END_TEST

// CEIL
START_TEST(s21_ceil_test_1) {
  double a = rand();
  a = a / RAND_MAX * 10;
  ck_assert_double_eq_tol(ceil(a), s21_ceil(a), ACCURACY);
}
END_TEST

START_TEST(s21_ceil_test_2) {
  double a = rand();
  a = a / RAND_MAX * (-10);
  ck_assert_double_eq_tol(ceil(a), s21_ceil(a), ACCURACY);
}
END_TEST

START_TEST(s21_ceil_test_3) {
  double a = 0.0;
  ck_assert_double_eq_tol(ceil(a), s21_ceil(a), ACCURACY);
}
END_TEST

START_TEST(s21_ceil_test_4) {
  double a = NAN;
  ck_assert_double_nan(ceil(a));
  ck_assert_double_nan(s21_ceil(a));
}
END_TEST

START_TEST(s21_ceil_test_5) {
  double a = INFINITY;

  ck_assert_double_infinite(ceil(a));
  ck_assert_double_infinite(s21_ceil(a));
}
END_TEST

START_TEST(s21_ceil_test_6) {
  double a = -INFINITY;

  ck_assert_double_infinite(ceil(a));
  ck_assert_double_infinite(s21_ceil(a));
}
END_TEST

// FMOD
START_TEST(s21_fmod_test_1) {
  double a = rand();
  a = a / RAND_MAX * 10;
  double b = rand();
  b = b / RAND_MAX * 10;
  ck_assert_double_eq_tol(fmod(a, b), s21_fmod(a, b), ACCURACY);
}
END_TEST

START_TEST(s21_fmod_test_2) {
  double a = NAN;
  double b = NAN;
  ck_assert_double_nan(fmod(a, b));
  ck_assert_double_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(s21_fmod_test_3) {
  double a = NAN;
  double b = 0;
  ck_assert_double_nan(fmod(a, b));
  ck_assert_double_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(s21_fmod_test_4) {
  double a = 0;
  double b = NAN;
  ck_assert_double_nan(fmod(a, b));
  ck_assert_double_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(s21_fmod_test_5) {
  double a = INFINITY;
  double b = 0;

  ck_assert_double_nan(fmod(a, b));
  ck_assert_double_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(s21_fmod_test_6) {
  double a = 0;
  double b = INFINITY;
  ck_assert_double_eq_tol(fmod(a, b), s21_fmod(a, b), ACCURACY);
}
END_TEST

START_TEST(s21_fmod_test_7) {
  double a = INFINITY;
  double b = INFINITY;
  ck_assert_double_nan(fmod(a, b));
  ck_assert_double_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(s21_fmod_test_8) {
  double a = -INFINITY;
  double b = -INFINITY;
  ck_assert_double_nan(fmod(a, b));
  ck_assert_double_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(s21_fmod_test_9) {
  double a = INFINITY;
  double b = -INFINITY;
  ck_assert_double_nan(fmod(a, b));
  ck_assert_double_nan(s21_fmod(a, b));
}
END_TEST

// EXP
START_TEST(s21_exp_test_1) {
  long double a = rand();
  a = a / RAND_MAX * 10;
  ck_assert_double_eq_tol(exp(a), s21_exp(a), ACCURACY);
}
END_TEST

START_TEST(s21_exp_test_2) {
  long double a = 0.0;
  ck_assert_double_eq_tol(exp(a), s21_exp(a), ACCURACY);
}
END_TEST

START_TEST(s21_exp_test_3) {
  long double a = NAN;
  ck_assert_double_nan(exp(a));
  ck_assert_double_nan(s21_exp(a));
}
END_TEST

START_TEST(s21_exp_test_4) {
  long double a = INFINITY;
  ck_assert_double_infinite(exp(a));
  ck_assert_double_infinite(s21_exp(a));
}
END_TEST

START_TEST(s21_exp_test_5) {
  long double a = -INFINITY;
  ck_assert_double_eq_tol(exp(a), s21_exp(a), ACCURACY);
}
END_TEST

START_TEST(s21_exp_test_6) {
  long double a = rand();
  a = a / RAND_MAX * (-10);
  ck_assert_double_eq_tol(exp(a), s21_exp(a), ACCURACY);
}
END_TEST

// LOG
START_TEST(s21_log_test_1) {
  long double a = rand();
  a = a / RAND_MAX * 10;
  ck_assert_double_eq_tol(log(a), s21_log(a), ACCURACY);
}
END_TEST

START_TEST(s21_log_test_2) {
  long double a = -5;
  ck_assert_double_nan(log(a));
  ck_assert_double_nan(s21_log(a));
}
END_TEST

START_TEST(s21_log_test_3) {
  long double a = INFINITY;
  ck_assert_double_infinite(log(a));
  ck_assert_double_infinite(s21_log(a));
}
END_TEST

START_TEST(s21_log_test_4) {
  long double a = -INFINITY;
  ck_assert_double_nan(log(a));
  ck_assert_double_nan(s21_log(a));
}
END_TEST

START_TEST(s21_log_test_5) {
  long double a = 0.0;
  ck_assert_double_infinite(log(a));
  ck_assert_double_infinite(s21_log(a));
}
END_TEST

// POW
START_TEST(s21_pow_test_1) {
  long double a = rand();
  long double b = rand();
  ck_assert_double_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(s21_pow_test_2) {
  long double a = rand() / RAND_MAX * 10;
  long double b = rand() / RAND_MAX * 10;
  ck_assert_double_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(s21_pow_test_3) {
  long double a = rand() / RAND_MAX * (-10);
  long double b = rand() / RAND_MAX * 10;
  ck_assert_double_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(s21_pow_test_4) {
  long double a = rand() / RAND_MAX * 10;
  long double b = rand() / RAND_MAX * (-10);
  ck_assert_double_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(s21_pow_test_5) {
  long double a = rand() / RAND_MAX * (-10);
  long double b = rand() / RAND_MAX * (-10);
  ck_assert_double_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(s21_pow_test_6) {
  long double a = 0;
  long double b = rand() / RAND_MAX * 10;
  ck_assert_double_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(s21_pow_test_7) {
  long double a = rand() / RAND_MAX * 10;
  long double b = 0;
  ck_assert_double_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(s21_pow_test_8) {
  long double a = 0.0;
  long double b = 0.0;
  ck_assert_double_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(s21_pow_test_9) {
  long double a = INFINITY;
  long double b = 7;
  ck_assert_double_infinite(pow(a, b));
  ck_assert_double_infinite(s21_pow(a, b));
}
END_TEST

START_TEST(s21_pow_test_10) {
  long double a = 8;
  long double b = INFINITY;
  ck_assert_double_infinite(pow(a, b));
  ck_assert_double_infinite(s21_pow(a, b));
}
END_TEST

START_TEST(s21_pow_test_11) {
  long double a = -INFINITY;
  long double b = 7;
  ck_assert_double_infinite(pow(a, b));
  ck_assert_double_infinite(s21_pow(a, b));
}
END_TEST

START_TEST(s21_pow_test_12) {
  long double a = 8;
  long double b = -INFINITY;
  ck_assert_double_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(s21_pow_test_13) {
  long double a = INFINITY;
  long double b = -INFINITY;
  ck_assert_double_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(s21_pow_test_14) {
  long double a = -INFINITY;
  long double b = INFINITY;
  ck_assert_double_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(s21_pow_test_15) {
  long double a = INFINITY;
  long double b = INFINITY;
  ck_assert_double_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(s21_pow_test_16) {
  long double a = 7;
  long double b = NAN;
  ck_assert_double_nan(pow(a, b));
  ck_assert_double_nan(s21_pow(a, b));
}
END_TEST

START_TEST(s21_pow_test_17) {
  long double a = NAN;
  long double b = 4;
  ck_assert_double_nan(pow(a, b));
  ck_assert_double_nan(s21_pow(a, b));
}
END_TEST

START_TEST(s21_pow_test_18) {
  long double a = NAN;
  long double b = NAN;
  ck_assert_double_nan(pow(a, b));
  ck_assert_double_nan(s21_pow(a, b));
}
END_TEST

// SIN
START_TEST(s21_sin_test_1) {
  long double a = rand();
  a = a / RAND_MAX * 100;
  ck_assert_double_eq_tol(sin(a), s21_sin(a), ACCURACY);
}

END_TEST
START_TEST(s21_sin_test_2) {
  long double a = 0.0;
  ck_assert_double_eq_tol(sin(a), s21_sin(a), ACCURACY);
}
END_TEST

END_TEST
START_TEST(s21_sin_test_3) {
  long double a = NAN;
  ck_assert_double_nan(sin(a));
  ck_assert_double_nan(s21_sin(a));
}
END_TEST

START_TEST(s21_sin_test_4) {
  long double a = INFINITY;
  ck_assert_double_nan(sin(a));
  ck_assert_double_nan(s21_sin(a));
}
END_TEST

START_TEST(s21_sin_test_5) {
  long double a = -INFINITY;
  ck_assert_double_nan(sin(a));
  ck_assert_double_nan(s21_sin(a));
}
END_TEST

START_TEST(s21_sin_test_6) {
  long double a = -43;
  ck_assert_double_eq_tol(sin(a), s21_sin(a), ACCURACY);
}
END_TEST

// COS
START_TEST(s21_cos_test_1) {
  double a = rand();
  a = a / RAND_MAX * 10;
  ck_assert_double_eq_tol(cos(a), s21_cos(a), ACCURACY);
}
END_TEST

START_TEST(s21_cos_test_2) {
  long double a = 0.0;
  ck_assert_double_eq_tol(cos(a), s21_cos(a), ACCURACY);
}
END_TEST

END_TEST
START_TEST(s21_cos_test_3) {
  long double a = NAN;
  ck_assert_double_nan(cos(a));
  ck_assert_double_nan(s21_cos(a));
}
END_TEST

START_TEST(s21_cos_test_4) {
  long double a = INFINITY;
  ck_assert_double_nan(cos(a));
  ck_assert_double_nan(s21_cos(a));
}
END_TEST

START_TEST(s21_cos_test_5) {
  long double a = -INFINITY;
  ck_assert_double_nan(cos(a));
  ck_assert_double_nan(s21_cos(a));
}
END_TEST

START_TEST(s21_cos_test_6) {
  long double a = -43;
  ck_assert_double_eq_tol(cos(a), s21_cos(a), ACCURACY);
}
END_TEST

// TAN
START_TEST(s21_tan_test_1) {
  long double a = rand();
  a = a / RAND_MAX * 10;
  ck_assert_double_eq_tol(tan(a), s21_tan(a), ACCURACY);
}
END_TEST

START_TEST(s21_tan_test_2) {
  long double a = rand();
  a = a / RAND_MAX * (-10);
  ck_assert_double_eq_tol(tan(a), s21_tan(a), ACCURACY);
}
END_TEST

START_TEST(s21_tan_test_3) {
  long double a = 0.0;
  ck_assert_double_eq_tol(tan(a), s21_tan(a), ACCURACY);
}
END_TEST

START_TEST(s21_tan_test_4) {
  long double a = NAN;
  ck_assert_double_nan(tan(a));
  ck_assert_double_nan(s21_tan(a));
}
END_TEST

START_TEST(s21_tan_test_5) {
  long double a = M_PI;
  ck_assert_double_eq_tol(tan(a), s21_tan(a), ACCURACY);
}
END_TEST

START_TEST(s21_tan_test_6) {
  long double a = INFINITY;
  ck_assert_double_nan(tan(a));
  ck_assert_double_nan(s21_tan(a));
}
END_TEST

START_TEST(s21_tan_test_7) {
  long double a = -INFINITY;
  ck_assert_double_nan(tan(a));
  ck_assert_double_nan(s21_tan(a));
}
END_TEST

// ATAN
START_TEST(s21_atan_test_1) {
  long double a = rand();
  a = a / RAND_MAX;
  ck_assert_double_eq_tol(atan(a), s21_atan(a), ACCURACY);
}
END_TEST

START_TEST(s21_atan_test_2) {
  long double a = rand();
  a = a / RAND_MAX * 10;
  ck_assert_double_eq_tol(atan(a), s21_atan(a), ACCURACY);
}
END_TEST

START_TEST(s21_atan_test_3) {
  long double a = INFINITY;
  ck_assert_double_eq_tol(atan(a), s21_atan(a), ACCURACY);
}
END_TEST

START_TEST(s21_atan_test_4) {
  long double a = -INFINITY;
  ck_assert_double_eq_tol(atan(a), s21_atan(a), ACCURACY);
}
END_TEST

START_TEST(s21_atan_test_5) {
  long double a = 1;
  ck_assert_double_eq_tol(atan(a), s21_atan(a), ACCURACY);
}
END_TEST

START_TEST(s21_atan_test_6) {
  long double a = -1;
  ck_assert_double_eq_tol(atan(a), s21_atan(a), ACCURACY);
}
END_TEST

START_TEST(s21_atan_test_7) {
  long double a = NAN;
  ck_assert_double_nan(atan(a));
  ck_assert_double_nan(s21_atan(a));
}
END_TEST

START_TEST(s21_atan_test_8) {
  long double a = rand();
  a = a / RAND_MAX * (-10);
  ck_assert_double_eq_tol(atan(a), s21_atan(a), ACCURACY);
}
END_TEST

// ASIN
START_TEST(s21_asin_test_1) {
  long double a = rand();
  a = a / RAND_MAX;
  ck_assert_double_eq_tol(asin(a), s21_asin(a), ACCURACY);
}
END_TEST
START_TEST(s21_asin_test_2) {
  long double a = 2.0;
  ck_assert_double_nan(asin(a));
  ck_assert_double_nan(s21_asin(a));
}
END_TEST
START_TEST(s21_asin_test_3) {
  long double a = -7.8;
  ck_assert_double_nan(asin(a));
  ck_assert_double_nan(s21_asin(a));
}
END_TEST
START_TEST(s21_asin_test_4) {
  long double a = -1.0;
  ck_assert_double_eq_tol(asin(a), s21_asin(a), ACCURACY);
}
END_TEST
START_TEST(s21_asin_test_5) {
  long double a = 1.0;
  ck_assert_double_eq_tol(asin(a), s21_asin(a), ACCURACY);
}
END_TEST
START_TEST(s21_asin_test_6) {
  long double a = NAN;
  ck_assert_double_nan(asin(a));
  ck_assert_double_nan(s21_asin(a));
}
END_TEST
START_TEST(s21_asin_test_7) {
  long double a = INFINITY;
  ck_assert_double_nan(asin(a));
  ck_assert_double_nan(s21_asin(a));
}
END_TEST
START_TEST(s21_asin_test_8) {
  long double a = -INFINITY;
  ck_assert_double_nan(asin(a));
  ck_assert_double_nan(s21_asin(a));
}
END_TEST

// ACOS
START_TEST(s21_acos_test_1) {
  long double a = rand();
  a = a / RAND_MAX;
  ck_assert_double_eq_tol(acos(a), s21_acos(a), ACCURACY);
}
END_TEST
START_TEST(s21_acos_test_2) {
  long double a = rand();
  a = a / RAND_MAX * (-1);
  ck_assert_double_eq_tol(acos(a), s21_acos(a), ACCURACY);
}
END_TEST
START_TEST(s21_acos_test_3) {
  long double a = -2;
  ck_assert_double_nan(acos(a));
  ck_assert_double_nan(s21_acos(a));
}
END_TEST
START_TEST(s21_acos_test_4) {
  long double a = 2;
  ck_assert_double_nan(acos(a));
  ck_assert_double_nan(s21_acos(a));
}
END_TEST
START_TEST(s21_acos_test_5) {
  long double a = NAN;
  ck_assert_double_nan(acos(a));
  ck_assert_double_nan(s21_acos(a));
}
END_TEST
START_TEST(s21_acos_test_6) {
  long double a = INFINITY;
  ck_assert_double_nan(acos(a));
  ck_assert_double_nan(s21_acos(a));
}
END_TEST
START_TEST(s21_acos_test_7) {
  long double a = -INFINITY;
  ck_assert_double_nan(acos(a));
  ck_assert_double_nan(s21_acos(a));
}
END_TEST
START_TEST(s21_acos_test_8) {
  long double a = -1.0;
  ck_assert_double_eq_tol(acos(a), s21_acos(a), ACCURACY);
}
END_TEST
START_TEST(s21_acos_test_9) {
  long double a = 1.0;
  ck_assert_double_eq_tol(acos(a), s21_acos(a), ACCURACY);
}
END_TEST
START_TEST(s21_acos_test_10) {
  long double a = 0;
  ck_assert_double_eq_tol(acos(a), s21_acos(a), ACCURACY);
}
END_TEST

Suite *s21_abs_suite(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_abs");
  tc = tcase_create("case_abs");
  for (int i = 0; i < 97; ++i) tcase_add_test(tc, s21_abs_test_1);
  tcase_add_test(tc, s21_abs_test_2);
  tcase_add_test(tc, s21_abs_test_3);
  tcase_add_test(tc, s21_abs_test_4);
  suite_add_tcase(s, tc);
  return s;
}

Suite *s21_fabs_suite(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_fabs");
  tc = tcase_create("case_fabs");
  for (int i = 0; i < 96; ++i) tcase_add_test(tc, s21_fabs_test_1);
  tcase_add_test(tc, s21_fabs_test_2);
  tcase_add_test(tc, s21_fabs_test_3);
  tcase_add_test(tc, s21_fabs_test_4);
  tcase_add_test(tc, s21_fabs_test_5);
  suite_add_tcase(s, tc);
  return s;
}

Suite *s21_sqrt_suite(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_sqrt");
  tc = tcase_create("case_sqrt");
  for (int i = 0; i < 94; ++i) tcase_add_test(tc, s21_sqrt_test_1);
  tcase_add_test(tc, s21_sqrt_test_2);
  tcase_add_test(tc, s21_sqrt_test_3);
  tcase_add_test(tc, s21_sqrt_test_4);
  tcase_add_test(tc, s21_sqrt_test_5);
  tcase_add_test(tc, s21_sqrt_test_6);
  tcase_add_test(tc, s21_sqrt_test_7);

  suite_add_tcase(s, tc);
  return s;
}

Suite *s21_floor_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_floor");

  tc = tcase_create("case_floor");

  for (int i = 0; i < 48; ++i) tcase_add_test(tc, s21_floor_test_1);
  for (int i = 0; i < 48; ++i) tcase_add_test(tc, s21_floor_test_2);
  tcase_add_test(tc, s21_floor_test_3);
  tcase_add_test(tc, s21_floor_test_4);
  tcase_add_test(tc, s21_floor_test_5);
  tcase_add_test(tc, s21_floor_test_6);

  suite_add_tcase(s, tc);
  return s;
}

Suite *s21_ceil_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_ceil");

  tc = tcase_create("case_ceil");

  for (int i = 0; i < 48; ++i) tcase_add_test(tc, s21_ceil_test_1);
  for (int i = 0; i < 48; ++i) tcase_add_test(tc, s21_ceil_test_2);
  tcase_add_test(tc, s21_ceil_test_3);
  tcase_add_test(tc, s21_ceil_test_4);
  tcase_add_test(tc, s21_ceil_test_5);
  tcase_add_test(tc, s21_ceil_test_6);

  suite_add_tcase(s, tc);
  return s;
}

Suite *s21_fmod_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_fmod");

  tc = tcase_create("case_fmod");

  for (int i = 0; i < 92; ++i) tcase_add_test(tc, s21_fmod_test_1);
  tcase_add_test(tc, s21_fmod_test_2);
  tcase_add_test(tc, s21_fmod_test_3);
  tcase_add_test(tc, s21_fmod_test_4);
  tcase_add_test(tc, s21_fmod_test_5);
  tcase_add_test(tc, s21_fmod_test_6);
  tcase_add_test(tc, s21_fmod_test_7);
  tcase_add_test(tc, s21_fmod_test_8);
  tcase_add_test(tc, s21_fmod_test_9);

  suite_add_tcase(s, tc);
  return s;
}

Suite *s21_exp_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_exp");

  tc = tcase_create("case_exp");

  for (int i = 0; i < 48; ++i) tcase_add_test(tc, s21_exp_test_1);
  for (int i = 0; i < 48; ++i) tcase_add_test(tc, s21_exp_test_6);
  tcase_add_test(tc, s21_exp_test_2);
  tcase_add_test(tc, s21_exp_test_3);
  tcase_add_test(tc, s21_exp_test_4);
  tcase_add_test(tc, s21_exp_test_5);

  suite_add_tcase(s, tc);
  return s;
}

Suite *s21_log_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_log");

  tc = tcase_create("case_log");

  for (int i = 0; i < 96; ++i) tcase_add_test(tc, s21_log_test_1);
  tcase_add_test(tc, s21_log_test_2);
  tcase_add_test(tc, s21_log_test_3);
  tcase_add_test(tc, s21_log_test_4);
  tcase_add_test(tc, s21_log_test_5);

  suite_add_tcase(s, tc);
  return s;
}

Suite *s21_pow_suite(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_pow");
  tc = tcase_create("case_pow");
  for (int i = 0; i < 17; ++i) tcase_add_test(tc, s21_pow_test_1);
  for (int i = 0; i < 17; ++i) tcase_add_test(tc, s21_pow_test_2);
  for (int i = 0; i < 17; ++i) tcase_add_test(tc, s21_pow_test_3);
  for (int i = 0; i < 18; ++i) tcase_add_test(tc, s21_pow_test_4);
  for (int i = 0; i < 18; ++i) tcase_add_test(tc, s21_pow_test_5);
  tcase_add_test(tc, s21_pow_test_6);
  tcase_add_test(tc, s21_pow_test_7);
  tcase_add_test(tc, s21_pow_test_8);
  tcase_add_test(tc, s21_pow_test_9);
  tcase_add_test(tc, s21_pow_test_10);
  tcase_add_test(tc, s21_pow_test_11);
  tcase_add_test(tc, s21_pow_test_12);
  tcase_add_test(tc, s21_pow_test_13);
  tcase_add_test(tc, s21_pow_test_14);
  tcase_add_test(tc, s21_pow_test_15);
  tcase_add_test(tc, s21_pow_test_16);
  tcase_add_test(tc, s21_pow_test_17);
  tcase_add_test(tc, s21_pow_test_18);

  suite_add_tcase(s, tc);
  return s;
}

Suite *s21_sin_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_sin");

  tc = tcase_create("case_sin");

  for (int i = 0; i < 95; ++i) tcase_add_test(tc, s21_sin_test_1);
  tcase_add_test(tc, s21_sin_test_2);
  tcase_add_test(tc, s21_sin_test_3);
  tcase_add_test(tc, s21_sin_test_4);
  tcase_add_test(tc, s21_sin_test_5);
  tcase_add_test(tc, s21_sin_test_6);

  suite_add_tcase(s, tc);
  return s;
}

Suite *s21_cos_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_cos");

  tc = tcase_create("case_cos");

  for (int i = 0; i < 95; ++i) tcase_add_test(tc, s21_cos_test_1);
  tcase_add_test(tc, s21_cos_test_2);
  tcase_add_test(tc, s21_cos_test_3);
  tcase_add_test(tc, s21_cos_test_4);
  tcase_add_test(tc, s21_cos_test_5);
  tcase_add_test(tc, s21_cos_test_6);

  suite_add_tcase(s, tc);
  return s;
}

Suite *s21_tan_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_tan");

  tc = tcase_create("case_tan");

  for (int i = 0; i < 45; ++i) tcase_add_test(tc, s21_tan_test_1);
  for (int i = 0; i < 50; ++i) tcase_add_test(tc, s21_tan_test_2);
  tcase_add_test(tc, s21_tan_test_3);
  tcase_add_test(tc, s21_tan_test_4);
  tcase_add_test(tc, s21_tan_test_5);
  tcase_add_test(tc, s21_tan_test_6);
  tcase_add_test(tc, s21_tan_test_7);

  suite_add_tcase(s, tc);
  return s;
}

Suite *s21_atan_suite(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_atan");
  tc = tcase_create("case_atan");
  for (int i = 0; i < 35; ++i) tcase_add_test(tc, s21_atan_test_1);
  for (int i = 0; i < 30; ++i) tcase_add_test(tc, s21_atan_test_2);
  for (int i = 0; i < 30; ++i) tcase_add_test(tc, s21_atan_test_8);
  tcase_add_test(tc, s21_atan_test_3);
  tcase_add_test(tc, s21_atan_test_4);
  tcase_add_test(tc, s21_atan_test_5);
  tcase_add_test(tc, s21_atan_test_6);
  tcase_add_test(tc, s21_atan_test_7);
  suite_add_tcase(s, tc);
  return s;
}

Suite *s21_asin_suite(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_asin");
  tc = tcase_create("case_asin");
  for (int i = 0; i < 30; ++i) tcase_add_test(tc, s21_asin_test_1);
  tcase_add_test(tc, s21_asin_test_2);
  tcase_add_test(tc, s21_asin_test_3);
  tcase_add_test(tc, s21_asin_test_4);
  tcase_add_test(tc, s21_asin_test_5);
  tcase_add_test(tc, s21_asin_test_6);
  tcase_add_test(tc, s21_asin_test_7);
  tcase_add_test(tc, s21_asin_test_8);
  suite_add_tcase(s, tc);
  return s;
}

Suite *s21_acos_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_acos");

  tc = tcase_create("case_acos");

  for (int i = 0; i < 46; ++i) tcase_add_test(tc, s21_acos_test_1);
  for (int i = 0; i < 46; ++i) tcase_add_test(tc, s21_acos_test_2);
  tcase_add_test(tc, s21_acos_test_3);
  tcase_add_test(tc, s21_acos_test_4);
  tcase_add_test(tc, s21_acos_test_5);
  tcase_add_test(tc, s21_acos_test_6);
  tcase_add_test(tc, s21_acos_test_7);
  tcase_add_test(tc, s21_acos_test_8);
  tcase_add_test(tc, s21_acos_test_9);
  tcase_add_test(tc, s21_acos_test_10);

  suite_add_tcase(s, tc);
  return s;
}

void case_test(Suite *s, int *fail) {
  SRunner *runner = srunner_create(s);
  srunner_set_fork_status(runner, CK_NOFORK);
  srunner_run_all(runner, CK_NORMAL);
  *fail = srunner_ntests_failed(runner);
  srunner_free(runner);
}

int main(void) {
  int fail = 0;

  case_test(s21_abs_suite(), &fail);
  case_test(s21_fabs_suite(), &fail);
  case_test(s21_sqrt_suite(), &fail);
  case_test(s21_floor_suite(), &fail);
  case_test(s21_ceil_suite(), &fail);
  case_test(s21_fmod_suite(), &fail);
  case_test(s21_exp_suite(), &fail);
  case_test(s21_log_suite(), &fail);
  case_test(s21_pow_suite(), &fail);
  case_test(s21_sin_suite(), &fail);
  case_test(s21_cos_suite(), &fail);
  case_test(s21_tan_suite(), &fail);
  case_test(s21_atan_suite(), &fail);
  case_test(s21_asin_suite(), &fail);
  case_test(s21_acos_suite(), &fail);

  return fail;
}
