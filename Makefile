# Makefile for Liar's Dice Game

# Compiler settings
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2
TARGET = liarDisc
SOURCE = liarDisc.c

# Default target
all: $(TARGET)

# Compile the game
$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

# Debug build
debug: CFLAGS += -g -DDEBUG
debug: $(TARGET)

# Clean build files
clean:
	rm -f $(TARGET) *.o *.exe

# Install (copy to /usr/local/bin on Unix-like systems)
install: $(TARGET)
	sudo cp $(TARGET) /usr/local/bin/

# Uninstall
uninstall:
	sudo rm -f /usr/local/bin/$(TARGET)

# Run the game
run: $(TARGET)
	./$(TARGET)

# Help
help:
	@echo "Available targets:"
	@echo "  all      - Build the game (default)"
	@echo "  debug    - Build with debug symbols"
	@echo "  clean    - Remove build files"
	@echo "  install  - Install to system (Unix-like)"
	@echo "  uninstall- Remove from system"
	@echo "  run      - Build and run the game"
	@echo "  help     - Show this help"

.PHONY: all debug clean install uninstall run help 