clean: run
	@del a.exe del bdconverter.h.gch

run: compile
	@./a

compile:
	@gcc -std=c11 bdconverter.h bdconverter.c main.c