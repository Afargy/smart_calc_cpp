# utilities
COMPILER = g++ 
# files
MAIN_SOURCE = *.cc \
							**/*.cc \
							**/**/*.cc \
							**/**/**/*.cc 
MAIN_HEADER = **/*.h \
							**/**/*.h \
							**/**/**/*.h 
TESTS_SOURCE = model/arithmetic_calculator/*.cc \
							 model/arithmetic_calculator/**/*.cc \
							 tests/*.cc
OBJECT_FILES = *.o
ARCHIVE = s21_matrix_oop.a
FOR_CLEAN = a.out $(OBJECT_FILES) $(ARCHIVE) valgrind_results.txt *.gcno *.info report
DESTDIR = build
# flags
COMPILER_FLAGS = -Wall -Werror -Wextra -std=c++17 -fsanitize=address
VALGRIND_FLAGS = --quiet --leak-check=full --track-origins=yes --trace-children=yes --tool=memcheck 
GCOV_FLAGS = -fprofile-arcs -ftest-coverage -fno-elide-constructors
TEST_FLAGS = $(COMPILER_FLAGS) -fsanitize=address
# libs
TESTS_LIBS = -lgtest -lpthread
GCOV_LIBS = -lgtest -lm -lpthread -lcheck
# runners and removers
EXECUTABLE = a.out
RUN_OUT = ./a.out
REMOVE = rm -rf

ifeq ($(shell uname), Linux)
LFLAGS = -lcheck -lsubunit -lm -lrt -lpthread
endif

QQQ = qmake


all: uninstall install

install:
	if [ ! -e build ]; then mkdir build ; fi
	$(QQQ) -o $(DESTDIR)/Makefile && cd $(DESTDIR) && make && make clean && rm Makefile

uninstall:
	rm -rf build

tests: clean
	$(COMPILER) $(TEST_FLAGS) $(TESTS_SOURCE) $(TESTS_LIBS) 
	$(RUN_OUT)

gcov: gcov_report

gcov_report: clean
	$(COMPILER) $(COPMILER_FLAGS) $(GCOV_FLAGS) $(TESTS_SOURCE) $(GCOV_LIBS)
	$(RUN_OUT)
	lcov --no-external -t "test" -o test.info -c -d . -d tests/.
	genhtml -o report test.info
	$(REMOVE) *.gcno *.gcda
	open ./report/index.html

style:
	clang-format -i -style=google $(MAIN_SOURCE) $(MAIN_HEADER)
	clang-format -n -style=google $(MAIN_SOURCE) $(MAIN_HEADER)

clean:
	make clean_for -s

clean_for:
	for elem in $(FOR_CLEAN); do\
		if [ -e $$elem ]; then\
			$(REMOVE) $$elem;\
		fi;\
	done

leaks: test
	leaks -atExit -- $(RUN_OUT)

dist:
	if [ ! -e build/smart_calculator_v2 ]; then make install ; fi
	@if [ -e Archive_Calc_v2.0 ]; then rm -rf Archive_Calc_v2.0 ; fi
	mkdir Archive_Calc_v2.0
	mkdir Archive_Calc_v2.0/src
	mv ./build/smart_calculator_v2 Archive_Calc_v2.0/src/
	tar cvzf Archive_Calc_v2.0.tgz Archive_Calc_v2.0/
	rm -rf Archive_Calc_v2.0/

dvi:
	open description.txt
