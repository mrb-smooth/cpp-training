PROJECT  = fibonacci

CXX      = clang++
CXXFLAGS = -std=c++2a -O2 -g -pedantic -Wall -Wextra -Werror

LD       = clang++
LDFLAGS  =

BIN      = ../bin
SRC      = src
OBJ      = build
BUILD    = $(OBJ)
SOURCES  = $(wildcard $(SRC)/*.cpp)
OBJECTS  = $(patsubst $(SRC)/%.cpp, $(OBJ)/%.obj, $(SOURCES))

INCLUDE  = include
INCLUDES = $(addprefix -I,$(INCLUDE))

all: $(PROJECT)

$(PROJECT): $(BIN) $(BUILD) $(OBJECTS) 
	$(LD) $(OBJECTS) $(LDFLAGS) -o $(BIN)/$(PROJECT)

$(OBJECTS): $(OBJ)/%.obj : $(SRC)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $^ -o $@

$(BIN):
	mkdir -p $@

$(BUILD):
	mkdir -p $@

clean:
	rm -fr bin/*
	rm -fr build/*
