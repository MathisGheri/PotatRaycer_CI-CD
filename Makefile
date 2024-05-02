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

re: clean all

clean: 
	cd build && make clean
