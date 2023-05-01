# Makefile for the test.me tool

# Sets the `make` command to silent mode by default if VERBOSE is not set (e.g. make VERBOSE=1)
ifndef VERBOSE
.SILENT:
endif

# tool macros
CC := gcc
CFLAGS := -Wno-sign-compare -Wfloat-equal -Wundef -Wcast-align -Wwrite-strings -Wlogical-op -Wredundant-decls -Wno-unused-parameter -Wno-unused-variable -Wshadow -Wall -Wextra
DBGFLAGS := -g
CCOBJFLAGS := $(CFLAGS) -c

# path macros
BIN_PATH := bin
OBJ_PATH := obj
SRC_PATH := .

ifeq ($(OS),Windows_NT)
	MKDIR_COMMAND := \
		if not exist $(BIN_PATH) (mkdir $(BIN_PATH)) & \
		if not exist $(OBJ_PATH) (mkdir $(OBJ_PATH))
else
	MKDIR_COMMAND := mkdir -p $(BIN_PATH) $(OBJ_PATH)
endif

# compile macros
TARGET_BASE_NAME := test.me
ifeq ($(OS),Windows_NT)
	TARGET_NAME := $(addsuffix .exe,$(TARGET_BASE_NAME))
else
	TARGET_NAME := $(TARGET_BASE_NAME)
endif
TARGET := $(BIN_PATH)/$(TARGET_NAME)

# src files
SRC := $(foreach x, $(SRC_PATH), $(wildcard $(addprefix $(x)/*,.c*)))
OBJ := $(addprefix $(OBJ_PATH)/, $(addsuffix .o, $(notdir $(basename $(SRC)))))

# clean files list
CLEAN_LIST := $(BIN_PATH) \
			  $(OBJ_PATH)

ifeq ($(OS),Windows_NT)
	RM_COMMAND := for %%a in ($(CLEAN_LIST)) do if exist "%%~a" (rmdir /s /q "%%~a")
else
	RM_COMMAND := rm -rf $(CLEAN_LIST)
endif

# clear screen
ifeq ($(OS),Windows_NT)
	CLS_COMMAND := cls
else
	CLS_COMMAND := clear
endif

# default rule
default: clean makedir all

# non-phony targets
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $<

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	$(CXX) $(CCOBJFLAGS) -o $@ $<

# phony rules
.PHONY: makedir
makedir:
	$(MKDIR_COMMAND)

.PHONY: all
all: $(TARGET)

.PHONY: clean
clean:
	$(RM_COMMAND)

.PHONY: run
run: default
	$(CLS_COMMAND)
	@echo Example run:
	@echo ./$(TARGET) ./example_input/Q03/solution.c ./example_input/Q03/tests/
	./$(TARGET) ./example_input/Q03/solution.c ./example_input/Q03/tests/

.PHONY: run_folders
run_folders: default
	$(CLS_COMMAND)
	@echo Example run:
	@echo ./$(TARGET) ./solution.c ./tests/ ./example_input/
	./$(TARGET) ./solution.c ./tests/ ./example_input/

.PHONY: valgrind
valgrind: default
	$(CLS_COMMAND)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET) ./example_input/Q03/solution.c ./example_input/Q03/tests/

.PHONY: help
help:
	@echo "Makefile for the test.me tool"
	@echo ""
	@echo "Usage 01: make"
	@echo "Usage 02: make [option]"
	@echo ""
	@echo "Target rules (options):"
	@echo "	run         	- Compiles and runs binary file with a single folder"
	@echo "	run_folders 	- Compiles and runs binary file with multiple folders"
	@echo "	valgrind	- Compiles and runs binary file using valgrind tool"
	@echo "	clean		- Removes files and folders created by running make"
	@echo "	help		- Prints a help message with target rules"
