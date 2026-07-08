.PHONY: all build test run clean distclean dev

# Default target
all: build

# Configure and build the project
build:
	@mkdir -p build
	@cmake -S . -B build -DBUILD_TESTING=ON
	@cmake --build build

# Configure for development (with compile_commands.json)
dev:
	@mkdir -p build
	@cmake -S . -B build -DBUILD_TESTING=ON -DCMAKE_EXPORT_COMPILE_COMMANDS=1
	@cmake --build build

# Run the tests
test:
	@cmake --build build --target test

# Run the application
run:
	@cmake --build build --target run

# Clean build artifacts
clean:
	@cmake --build build --target clean

# Remove the entire build directory
distclean:
	@rm -rf build

.DEFAULT_GOAL := all
