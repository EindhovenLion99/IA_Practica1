CXX		  := g++
<<<<<<< HEAD
CXX_FLAGS := -Wall -Wextra -std=c++14 -ggdb
=======
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb
>>>>>>> 16afa4cbe789c32f69f2121d6ef9d5d48e4eb4a5

BIN		:= bin
SRC		:= src
INCLUDE	:= include
LIB		:= lib

LIBRARIES	:=
EXECUTABLE	:= main


all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*
