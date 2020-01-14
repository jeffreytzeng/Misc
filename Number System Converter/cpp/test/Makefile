clean: run
	@del a.exe

run: compile
	@./a

compile:
	@g++ -std=gnu++11 -L../../../lib -I../../../googletest/include -I../../../googletest/src -I../src ../src/bdconverter.cpp test.cpp test_main.cpp -lgtest -lpthread
