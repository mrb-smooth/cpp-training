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
run-tests: $(PROJECT)

$(PROJECT): data.db
$(PROJECT): $(BIN) $(BUILD) dependencies
	$(CMAKE) --build $(BUILD)

.PHONY: dependencies
dependencies:
	$(CMAKE) -B $(BUILD)

.PHONY: run-tests
run-tests:
	./Bin/run-tests

data.db:
	mkdir -p Data
	touch Data/$@

$(BIN):
	mkdir -p $@

$(BUILD):
	mkdir -p $@

.PHONY: clean
clean:
	rm -fr Bin/*
	rm -fr Build/*
	rm -fr Logs/*
	rm -fr Data/*
	rm -f  run-tests

.PHONY: extra-clean
extra-clean:
	rm -fr Bin
	rm -fr Build
	rm -fr Logs
	rm -fr Data
	rm -f  run-tests
