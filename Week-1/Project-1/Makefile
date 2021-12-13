PROJECT  = bank-cli

CXX      = clang++
CXXFLAGS = -std=c++17 -O2 -g -pedantic -Wall -Wextra -Werror

LD       = clang++
LDFLAGS  =

BIN      = bin
BUILD    = build

SRC      = src
OBJ      = build
SOURCES  = $(wildcard $(SRC)/*.cpp)
OBJECTS  = $(patsubst $(SRC)/%.cpp,$(OBJ)/%.obj,$(SOURCES))

INCLUDE  = include
INCLUDES = $(addprefix -I,$(INCLUDE))

all: $(PROJECT)
test: tests
$(PROJECT): data.csv

$(PROJECT): $(BIN) $(BUILD) $(OBJECTS) 
	$(LD) $(OBJECTS) $(LDFLAGS) -o $(BIN)/$(PROJECT)

$(OBJECTS): $(OBJ)/%.obj : $(SRC)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $^ -o $@

data.csv:
	echo "Account Id,Customer Name,Date Opened,SSN"     > $@
	echo "1123456789,John Doe,2021-12-13,155-55-5555"   >> $@
	echo "2123456789,Jane Doe,2021-12-13,255-55-5555"   >> $@
	echo "3123456789,George Doe,2021-12-13,355-55-5555" >> $@

.PHONY: tests
tests: data.csv
	$(CXX) $(CXXFLAGS) -Iinclude -Itests \
	tests/*.cpp src/Authentication.cpp src/DataBase.cpp \
	-o run-tests

$(BIN):
	mkdir -p $@

$(BUILD):
	mkdir -p $@

clean:
	rm -fr bin/*
	rm -fr build/*
	rm -f  run-tests

extra-clean:
	rm -fr bin
	rm -fr build
	rm -f  run-tests
	rm -f data.csv
