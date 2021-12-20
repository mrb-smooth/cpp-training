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
tests:
	$(CXX) -std=c++17 -Wall -Wextra \
	`pkg-config --cflags --libs protobuf` \
	-IIncludes -ITests -Ibuild \
	Tests/*.cpp \
	Sources/Authentication.cpp Sources/DataBase.cpp Sources/Logging.cpp \
	build/Account.pb.cc \
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
