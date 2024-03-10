TEST_APP = test_linkedlist
TARGET_LIB = linkedlistlib.so

CC = "/opt/homebrew/bin/gcc-13"
AR = "/opt/homebrew/bin/gcc-ar-13"

CFLAGS = -Wall -Wextra -Werror -O2 -g -std=c2x -pedantic # Compiler flags
LDFLAGS = -shared # Linker flags (shared library)  (change to -static for static library)

SRC_DIR := src
OBJ_DIR := obj
LIB_DIR := lib

TEST_SRC_DIR := tests
TEST_OBJ_DIR := obj
BUILD_DIR := build

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

TEST_FILES = $(wildcard $(TEST_SRC_DIR)/*.c)
TEST_OBJS = $(TEST_FILES:$(TEST_SRC_DIR)/%.c=$(TEST_OBJ_DIR)/%.o)

INCLUDE_DIRS = -Iinclude

# Targets
.PHONY: all clean

.PHONY: all
all: $(TARGET_LIB)

$(TARGET_LIB): $(OBJ_FILES) | $(LIB_DIR)
	$(CC) $(LDFLAGS) -o $(LIB_DIR)/$@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) -c -o $@ $<

.PHONY: test
test: $(TEST_APP)
	@echo "Running tests..."
	./$(BUILD_DIR)/$(TEST_APP)

$(TEST_APP): $(TEST_OBJS) $(LIB_DIR)/$(TARGET_LIB) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) -o $(BUILD_DIR)/$@ $^

$(TEST_OBJ_DIR)/%.o: $(TEST_SRC_DIR)/%.c | $(TEST_OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) -c -o $@ $<

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIB_DIR):
	@mkdir -p $(LIB_DIR)

.PHONY: clean
clean:
	@rm -rf $(BUILD_DIR)
	@rm -rf $(OBJ_DIR)
	@rm -rf $(LIB_DIR)
