CXX=clang++
CXX_FLAGS=-std=c++20 -Werror -Wall -Wextra -Iddd/inc

CXX_SRCS=ddd/lib/box.cpp       \
         ddd/lib/caster.cpp    \
				 ddd/lib/position.cpp  \
				 ddd/lib/screen.cpp    \
				 ddd/lib/sphere.cpp    \
				 ddd/program.cpp

OBJ_FILES=$(patsubst %.cpp,%.o,$(CXX_SRCS))
BINARY=bin/ddd

.PHONY: all
all: $(BINARY)

$(BINARY): $(OBJ_FILES)
	$(CXX) -o $(BINARY) $(OBJ_FILES)

%.o: %.cpp Makefile
	$(CXX) $(CXX_FLAGS) -c -o $@ $<

.PHONY: format
format:
	find . -name '*.hpp' | xargs clang-format -i
	find . -name '*.cpp' | xargs clang-format -i

.PHONY: clean
clean:
	find . -name '*.o' -delete
	rm $(BINARY)