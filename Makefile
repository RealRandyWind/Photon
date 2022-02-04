NAME = photon
FLEX_OUT := lex.yy
YACC_OUT := y.tab
SRC := $(NAME).c $(FLEX_OUT).c $(YACC_OUT).c
CXX ?= gcc
COMPILE_FLAGS = -lfl -std=c++98 -padantic -Wall -Wextra -g -x=c -DDEBUG;
TESTS := $(patsubst %.in, %.out, $(wildcard tests/*.in))

.PHONY: all clean-all

all: build

build: flex-build
	$(CXX) -o a.out $(SRC) $(COMPILE_FLAGS)

flex-build: yacc-build
	flex $(NAME).fl

yacc-build: $(NAME).ya
	yacc -d $(NAME).ya

clean:
	rm -f ./a.out ./$(FLEX_OUT).c ./$(YACC_OUT).c ./$(YACC_OUT).h