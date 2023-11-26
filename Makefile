CXX=clang++
CXX_FLAGS=-std=c++20 -Werror -Wall -Wextra -fsanitize=undefined

.PHONY: all
all:
	$(CXX) $(CXX_FLAGS) -o /tmp/ddd ddd/program.cpp
	/tmp/ddd > /tmp/ddd.ppm
	open /tmp/ddd.ppm

.PHONY: format
format:
	clang-format ddd/program.cpp
