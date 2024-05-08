# 325483444 gidirabi111@gmail.com
# !make -f

CXX=clang++
CXXFLAGS=-std=c++11 -Werror -Wsign-conversion
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all --error-exitcode=99

SOURCES=Graph.cpp Algorithms.cpp
MAIN_SOURCES=Main.cpp $(SOURCES)
TEST_SOURCES=TestCounter.cpp Test.cpp $(SOURCES)

MAIN_OBJECTS=$(subst .cpp,.o,$(MAIN_SOURCES))
TEST_OBJECTS=$(subst .cpp,.o,$(TEST_SOURCES))

all: main test

main: $(MAIN_OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o main

test: $(TEST_OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o test

tidy:
    clang-tidy $(SOURCES) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --

valgrind: main test
    valgrind --tool=memcheck $(VALGRIND_FLAGS) ./main 2>&1 | { egrep "lost| at " || true; }
    valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

%.o: %.cpp
	$(CXX) $(CXXFLAGS) --compile $< -o $@

clean:
	rm -f *.o main test