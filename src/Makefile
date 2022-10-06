CFLAGS=-Wall -Wextra -Werror -std=c11 $(shell pkg-config --cflags check)
TEST_FLAGS=$(shell pkg-config --libs check)

C_FILES=stack_char.c stack_double.c dijkstra_algorithm.c check_string.c calculation_algorithm.c
C_TEST_FILES= test/binary_operations_test.c test/functions_test.c test/s21_test.c
CPP_FILES=./qtPart/main.cpp ./qtPart/mainwindow.cpp ./qtPart/qcustomplot.cpp
H_FILES=s21_smartcalc.h
H_FILES+=./qtPart/qcustomplot.h ./qtPart/mainwindow.h
GUI_FILES=./qtPart/qtPart.pro ./qtPart/Makefile
O_FILES=stack_char.o stack_double.o dijkstra_algorithm.o check_string.o calculation_algorithm.o
O_TEST_FILES= binary_operations_test.o functions_test.o s21_test.o

ifeq ($(shell uname -s), Linux)
    TEST_FLAGS +=-lsubunit
endif

all: build

build: install gcov_report
	open ./qtPart/qtPart.app/Contents/MacOS/qtPart

install: $(H_FILES) $(C_FILES) $(CPP_FILES) $(C_TEST_FILES)
	bash installScript.sh
	$(MAKE) -C qtPart

uninstall:
	rm -rf ./qtPart/moc_predefs.h
	rm -rf ./qtPart/ui_mainwindow.h
	rm -rf ./qtPart/moc_qcustomplot.cpp
	rm -rf ./qtPart/moc_mainwindow.cpp
	rm -rf ./qtPart/.qmake.stash
	rm -rf ./qtPart/*.o
	rm -rf ./qtPart/qtPart.app

clean:
	rm -rf *.o *.html *.gcda *.gcno *.css *.out *.info report docs .clang-format

dvi: ./qtPart
	bash dviScript.sh

dist: $(C_FILES) $(CPP_FILES) $(H_FILES) $(GUI_FILES) Makefile
	mkdir -p ./dist
	tar cvzf ./dist/SmartCalc_1.0.tgz $(C_FILES) $(CPP_FILES) $(H_FILES) $(GUI_FILES) Makefile

tests: $(O_FILES) $(O_TEST_FILES)
	gcc -o test.out $(O_FILES) $(O_TEST_FILES) $(TEST_FLAGS)
	./test.out

gcov_report: $(H_FILES) $(C_FILES) $(C_TEST_FILES)
	gcc $(CFLAGS) --coverage -o make_report.out $(C_FILES) $(TEST_FLAGS) $(C_TEST_FILES)
	./make_report.out
	lcov -t "make_report" -o make_report.info -c -d .
	genhtml -o report make_report.info
	open report/index.html

style: clean
	cppcheck *.h *.c
	cp ../materials/linters/.clang-format .clang-format
	clang-format -n *.c *.h test/*.c test/*.h qtPart/*.cpp qtPart/*.h

$(O_FILES): $(C_FILES)
	gcc $(CFLAGS)  -c stack_char.c
	gcc $(CFLAGS)  -c stack_double.c
	gcc $(CFLAGS)  -c dijkstra_algorithm.c
	gcc $(CFLAGS)  -c calculation_algorithm.c
	gcc $(CFLAGS)  -c check_string.c

$(O_TEST_FILES): $(C_TEST_FILES)
	gcc  $(CFLAGS)  -c test/binary_operations_test.c
	gcc  $(CFLAGS)  -c test/functions_test.c
	gcc  $(CFLAGS)  -c test/s21_test.c
