
CXX=g++

BIN=gameoflife

SRC=../src
HEADER=../include

CXXFLAGS += -g -Wall -Wextra -pthread

SRCS_=$(SRC)/*.cpp $(HEADER)

main.o : $(SRC_)
	$(CXX) $(CXXFLAGS) -I$(HEADER) -c $(SRC)/main.cpp

all: $(BIN)

clean : 
	rm -f $(BIN) *.o

gameoflife : main.o 
	$(CXX) $(CXXFLAGS) -lpthread $^ -o $@