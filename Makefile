CC=clang++
CFLAGS=-std=c++20 -c -Wall

SOURCES=constants.cpp commands.cpp main.cpp
OBJECTS=$(SOURCES:.cpp=.o)

SRC_DIR=src/
INC_DIR=include/
BUILD_DIR=build/

EXECUTABLE := main

$(EXECUTABLE): $(addprefix $(BUILD_DIR), $(OBJECTS))
	$(CC) $(addprefix $(BUILD_DIR), $(OBJECTS)) -o $(BUILD_DIR)$(EXECUTABLE)

$(BUILD_DIR)main.o: $(SRC_DIR)main.cpp
	$(CC) $(CFLAGS) $< -o $@


$(BUILD_DIR)%.o: $(SRC_DIR)%.cpp $(INC_DIR)%.hpp | $(BUILD_DIR) $(INC_DIR)
	$(CC) $(CFLAGS) $< -o $@





clean: | $(BUILD_DIR)
	rm $(BUILD_DIR)*
