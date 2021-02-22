CXX = g++
CXX_FLAGS = -I. -std=c++17 -Wfatal-errors -Wall -Wextra -Wpedantic -Wconversion -Wshadow

TMPFILE=tmpimg
GEOM?=
VARS?=

ifdef GEOM
VARS += -V geometry:"$(GEOM)"
endif

PRJ = main
SRC = $(PRJ).cpp
BIN = a.out

.PHONY : all clean test score1 score2 score3 score4

all: $(BIN)

test.o: test.cpp
	$(CXX) $(CXX_FLAGS) test.cpp -c

$(BIN): test.o $(PRJ).o
	g++ $(CXX_FLAGS) test.o $(SRC)

solution: sol2pdf imgpdf clean

imgpdf:
	pdftoppm $(PRJ)-t.pdf $(TMPFILE) -png
	convert $(TMPFILE)*.png $(PRJ).pdf

sol2pdf:
	enscript --color=1 -C -Ecpp -fCourier9 -o - $(PRJ).sol.* | ps2pdf - $(PRJ)-t.pdf

clean:
	@rm $(PRJ)-t.pdf $(TMPFILE)*.png || true
	rm $(BIN) *.o | true

test: $(BIN)
	./$(BIN)

t1: $(BIN)
	./$(BIN) -c t1

t2: $(BIN)
	./$(BIN) -c t2

t3: $(BIN)
	./$(BIN) -c t3

t4: $(BIN)
	./$(BIN) -c t4

t5: $(BIN)
	./$(BIN) -c t5

t6: $(BIN)
	./$(BIN) -c t6

t7: $(BIN)
	./$(BIN) -c t7

t8: $(BIN)
	./$(BIN) -c t8

t9: $(BIN)
	./$(BIN) -c t9

t10: $(BIN)
	./$(BIN) -c t10

