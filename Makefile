APP_NAME = geometry
TEST_NAME = testing
LIB_NAME = libgeometry

CC = g++

CFLAGS = -Wall -Werror
CFLAGS_TEST = -I src -I thirdparty
CPPFLAGS = -I src

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src
TEST_DIR = test

APP_PATH = $(BIN_DIR)/$(APP_NAME)
LIB_PATH = $(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)/$(LIB_NAME).a
TEST_PATH = $(BIN_DIR)/$(TEST_NAME)
TEST_OBJ_PATH = $(OBJ_DIR)/$(TEST_DIR)

SRC_EXT = cpp
APP_RUN = $(BIN_DIR)/./$(APP_NAME)
TEST_CHECK = $(BIN_DIR)/./$(TEST_NAME)

APP_SOURCES = $(shell find $(SRC_DIR)/$(APP_NAME) -name '*.$(SRC_EXT)')
APP_OBJECTS = $(APP_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%.o)

LIB_SOURCES = $(shell find $(SRC_DIR)/$(LIB_NAME) -name '*.$(SRC_EXT)')
LIB_OBJECTS = $(LIB_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%.o)

TEST_SOURCES = $(shell find $(TEST_DIR) -name '*.$(SRC_EXT)')
TEST_OBJECTS = $(TEST_SOURCES:$(TEST_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(TEST_DIR)/%.o)

DEPS = $(APP_OBJECTS:.o=.d) $(LIB_OBJECTS:.o=.d)

.Geom: all
all: $(APP_PATH)

-include $(DEPS)

$(APP_PATH): $(APP_OBJECTS) $(LIB_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $^

$(LIB_PATH): $(LIB_OBJECTS)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: %.cpp
	$(CC) -c $(CFLAGS) $(CFLAGS_TEST) $< -o $@

.Geom: test_comp
test_comp: $(TEST_PATH)

$(TEST_PATH): $(TEST_OBJECTS) $(LIB_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $^

.Geom: clean
clean:
	rm -f $(APP_PATH) $(TEST_PATH) $(LIB_PATH) 
	rm -rf $(DEPS) $(APP_OBJECTS) $(LIB_OBJECTS)
	rm -rf $(TEST_OBJ_PATH)/*.*
	
.Geom: run
run: $(APP_RUN)
	$(APP_RUN)
	
.Geom: test_show
test_show: $(TEST_CHECK)
	$(TEST_CHECK)
	
.Geom: test
test:
	make test_comp
	make test_show

.Geom: start
start:
	make clean
	make
	make run
	make test_comp
	make test_show