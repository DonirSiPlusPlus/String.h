OS=$(shell uname)
ifeq ($(OS), Linux)
 LIBS=-lcheck -lpthread -lrt -lm -lsubunit
 OPEN=xdg-open
 LEAKS=CK_FORK=no valgrind -s --tool=memcheck --leak-check=full --show-leak-kinds=all --show-reachable=yes ./test.out
else
 LIBS=-lcheck
 OPEN=open
 LEAKS=CK_FORK=no leaks --atExit -- ./test.out
endif

all: s21_string.a cpplint test leaks cppcheck

s21_str.o: s21_string.c s21_string.h
	gcc -c s21_string.c

test:
	gcc test.c s21_string.c -o s21_test -lcheck

test_val:
	gcc test.c s21_string.c -o s21_test.out -lcheck

gcov_report: 
	gcc --coverage test.c s21_string.c -o s21_test -lcheck
	./s21_test
	lcov -t s21_test -o test.info -c -d .
	genhtml -o report test.info

s21_string.a : s21_str.o
	ar -cr s21_string.a s21_string.o

val : test_val
	CK_FORK=no valgrind -s --tool=memcheck --leak-check=full --show-leak-kinds=all --show-reachable=yes ./a.out

cpplint:
	python3 ../materials/linters/cpplint.py --extensions=c *.c

leaks: test
	leaks -atExit -- ./s21_test

cppcheck:
	cppcheck *;

clean: 
	rm -Rf *.o
	rm -Rf *.gcda
	rm -Rf *.gcno
	rm -Rf report
	rm -Rf *.a
	rm -Rf *.info
	rm -Rf s21_test
	rm -Rf main
	rm -Rf main.c

