PROJECT  = bank-cli-2

CMAKE    = /bin/cmake
CXX      = /bin/clang++

BIN      = Bin
BUILD    = Build

SRC      = Sources
OBJ      = $(BUILD)/CMakeFiles/$(PROJECT).dir/$(SRC)
SOURCES  = $(wildcard $(SRC)/*.cpp)
OBJECTS  = $(patsubst $(SRC)/%.cpp,$(OBJ)/%.cpp.o,$(SOURCES))

all: $(PROJECT)
test: tests

$(PROJECT): data.db
$(PROJECT): $(BIN) $(BUILD) dependencies
	$(CMAKE) --build $(BUILD)

.PHONY: dependencies
dependencies:
	$(CMAKE) -B $(BUILD)

data.db:
	mkdir -p Data
	echo -e "\n" > Data/$@

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
	rm -fr Bin/*
	rm -fr Build/*
	rm -fr Logs/*
	rm -fr Data/*
	rm -f  run-tests

extra-clean:
	rm -fr Bin
	rm -fr Build
	rm -fr Logs
	rm -fr Data
	rm -f  run-tests
