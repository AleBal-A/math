cc = gcc -Wall -Werror -Wextra -g
check = -lcheck

all:
	$(cc) $(check) -c test.c s21_abs.c s21_fabs.c s21_sqrt.c s21_floor.c s21_ceil.c s21_fmod.c s21_exp.c s21_factorial.c s21_log.c s21_pow.c  s21_pow_int.c s21_sin.c s21_cos.c s21_tan.c s21_atan.c s21_asin.c s21_acos.c
	$(cc)  -o test test.o s21_abs.o s21_fabs.o s21_sqrt.o s21_floor.o s21_ceil.o s21_fmod.o s21_exp.o s21_factorial.o s21_log.o s21_pow.o s21_pow_int.o s21_sin.o s21_cos.o s21_tan.o s21_atan.o s21_asin.o s21_acos.o
	rm -rf *.o

s21_math.a:
	$(cc) -c test.c s21_abs.c s21_fabs.c s21_sqrt.c s21_floor.c s21_ceil.c s21_fmod.c s21_exp.c s21_factorial.c s21_log.c s21_pow.c  s21_pow_int.c s21_sin.c s21_cos.c s21_tan.c s21_atan.c s21_asin.c s21_acos.c
	ar -rc s21_math.a *o
	ranlib s21_math.a
	rm -rf *.o

checks:
	cppcheck enable=all missingIncludeSystem *.c
	clang-format -i *.c
	clang-format -i *.h

clean: 
	rm -rf *.o
	rm -rf *.a
	rm -rf test

rebuild : clean s21_test
	clear