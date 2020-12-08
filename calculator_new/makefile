CXX			:= g++
CXX_FLAGS	:= -Wall -Wextra -std=c++11

BIN			:= bin
INCLUDE		:=
LIB			:=
LIBRARIES	:= 
EXECUTABLE	:= calculator.out

all: $(BIN)/$(EXECUTABLE) 

run: clean all
	@echo "Exexuting..."
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): src/*.cpp
	@echo "Building..."
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)

clean:
	@echo "Cleaning..."
	-rm $(BIN)/*
