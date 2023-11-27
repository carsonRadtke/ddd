CXX=g++
CXX_FLAGS=-std=c++20 -Werror -Wall -Wextra -Iddd/inc -fsanitize=address,undefined
LD_FLAGS=-fsanitize=address

CXX_SRCS=ddd/lib/box.cpp       \
         ddd/lib/caster.cpp    \
				 ddd/lib/position.cpp  \
				 ddd/lib/screen.cpp    \
				 ddd/lib/sphere.cpp    \
				 ddd/lib/color.cpp     \
				 ddd/program.cpp

OBJ_FILES=$(patsubst %.cpp,%.o,$(CXX_SRCS))
DEP_FILES=$(patsubst %.cpp,%.d,$(CXX_SRCS))
BINARY=bin/ddd

.PHONY: all
all: $(BINARY)

-include $(DEP_FILES)
$(BINARY): $(OBJ_FILES)
	$(CXX) $(LD_FLAGS) -o $(BINARY) $(OBJ_FILES)

%.o: %.cpp Makefile
	$(CXX) $(CXX_FLAGS) -MMD -MP -c -o $@ $<

.PHONY: format
format:
	find . -name '*.[hc]pp' | xargs clang-format -style=file -i

.PHONY: clean
clean:
	find . -name '*.[od]' -delete
	rm -f $(BINARY)
	