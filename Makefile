CC = gcc
FLAGS = -Wall -Werror -Wextra -std=c11

OS = $(shell uname)

ifeq ($(OS),Linux)
    det_OS = -lcheck  -lm -lrt -lpthread -lsubunit
else
    det_OS = -lcheck -lm -lpthread
endif


all: clean test gcov_report install

s21_smart_calc.o:  s21*
	$(CC) $(CFLAGS) s21*.c  -c 

s21_smart_calc.a : s21_smart_calc.o
	ar rcs s21_smart_calc.a *.o
	ranlib s21_smart_calc.a

install: uninstall
	cd calculator_pank && qmake calculator_pank.pro && make && make clean && rm Makefile && mkdir ../build && mv calculator_pank.app/$(UI_BIN) ../build/

uninstall:
	rm -rf build


dvi:
	open ./doc.md


dist: install
	mkdir -p dist
	cp  -R ./build/calculator_pank.app ./dist/calculator_pank.app
	cp ./doc.md ./dist/doc.md
	cd ./dist && tar cvzf calculator_pank.tgz *
	cd ./dist && rm -R calculator_pank.app doc.md
	make clean


test: clean
	$(CC) $(FLAGS) --coverage s21*.c tests.c -o test $(det_OS)
	./test

gcov_report: test
	./test
	lcov -t "result" -o res.info -c -d .
	genhtml -o report res.info
	open report/index.html




clean:
	rm -rf main *.o test *.g* report res.info dist 
