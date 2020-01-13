clean: run
	@del a.exe del ..\src\bdconverter.h.gch

run: compile
	@ ./a

compile:
	@g++ -std=gnu++11 -L../../../lib -I../../../googletest/include -I../../../googletest/src -I../src ../src/bdconverter.h ../src/bdconverter.c test_main.cpp test.cpp -lgtest -lpthread