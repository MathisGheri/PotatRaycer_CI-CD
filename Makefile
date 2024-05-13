##
## EPITECH PROJECT, 2024
## PotatRaycer_CI-CD
## File description:
## Makefile
##

all: 
	@mkdir -p build && cd build && cmake .. && make && cd ..

run: all
	./raytracer config.cfg

re: clean
	rm -rf build
	@mkdir -p build && cd build && cmake .. && make && cd ..

clean:
	@cd build && make clean
	rm -rf build
	rm -rf vgcore.*
	rm -rf logfile.txt

fclean: clean
