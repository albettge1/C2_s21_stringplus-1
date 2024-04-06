CC = gcc
CFLAGS = -std=c11 -Wall -Werror -Wextra
TARGET = s21_string.a
NEW_TEST_SRC=$(wildcard *.c)
LINUX_FLAGS=-lpthread -lcheck -pthread -lrt -lm -lsubunit
LIBS=-lcheck

all: build

build: s21_string.a

rebuild: clean build

s21_string.a:
	$(CC) $(CFLAGS) *.c -c
	ar rcs s21_string.a *.o
	ranlib s21_string.a

test: $(TARGET) 
ifeq ($(OS), Darwin)
	${CC} $(CFLAGS) ${NEW_TEST_SRC} $(TARGET) -o lib_test $(LIBS)
else
	${CC} $(CFLAGS) ${NEW_TEST_SRC} $(TARGET) -o lib_test $(LIBS) $(LINUX_FLAGS)
endif
	./lib_test

gcov_report:
	make test
	lcov -t "s21_string_test" -o test.info -c -d .
	genhtml -o report/ test.info

clean:
	rm -rf *.a *.o *.info *.gcda *.gcno *.gcov report test tests/*.gcno

style:
	clang-format -style=Google -i *.c *.h tests/*.c