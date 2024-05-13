# EPITECH PROJECT, 2024
# PotatRaycer_CI-CD
# File description:
# Makefile

all:
	@mkdir -p build && cd build && cmake .. && make && cd ..

run: all
	./raytracer config.cfg

test:
	@mkdir -p build && cd build && cmake .. && make run_tests && cd ..

re: clean
	rm -rf build
	@mkdir -p build && cd build && cmake .. && make && cd ..

clean:
	@cd build && make clean
