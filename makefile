# -- Windows + MinGW

# to compile use: 		mingw32-make

# to run use: 			./build/tic-tac-toe

# to clean use: 	 	mingw32-make clean



# -- Linux / macOS / MSYS2

# to compile use: 		make

# to run use: 			./build/tic-tac-toe

# to clean use: 		make clean


# Default compiler: GCC
# Change CC if you use another compiler
CC = gcc 

# Compilation flags:
# -Wall/-Wextra → show warnings
# -Iinclude     → header files location
CFLAGS = -Wall -Wextra -Iinclude

# Object files
OBJ = build/main.o build/game.o build/board.o build/input.o build/messages.o

# Final executable
TARGET = build/tic-tac-toe

# Targets that are not real files
.PHONY: clean


# Link object files into final executable
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)


# Pattern rule:
# Compile src/file.c → build/file.o
build/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@


# Remove compiled files
clean:
	rm -f build/*.o $(TARGET)
