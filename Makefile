# EPITECH PROJECT, 2024
# PotatRaycer_CI-CD
# File description:
# Makefile

.PHONY: all run test re clean fclean

all: build/raytracer

build/raytracer:
	@mkdir -p build && cd build && cmake .. && make

run: all
	@./build/raytracer config.cfg

test:
	@echo "Running tests..."
	@cd tests && mkdir -p build && cd build && cmake .. && make
	mv tests/build/run_tests tests
	@echo "Tests completed."

re: fclean all

clean:
	@cd build && make clean || true
	@cd tests/build && make clean || true
	@rm -rf build
	@rm -rf tests/build
	@rm -rf tests/run_tests
	@rm -rf tests/coverage*
	@rm -f vgcore.*
	@rm -f logfile.txt

fclean: clean
