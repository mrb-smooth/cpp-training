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
	echo "Account Id,Customer Name,Date Opened,SSN"      > Data/$@
	echo "1123456789,John Doe,2021-12-13,155-55-5555"   >> Data/$@
	echo "2123456789,Jane Doe,2021-12-13,255-55-5555"   >> Data/$@
	echo "3123456789,George Doe,2021-12-13,355-55-5555" >> Data/$@

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
