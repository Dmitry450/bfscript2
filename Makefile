all: bfscript2

bfscript2: bfscript2.o functions.o code_generator.o
	g++ bfscript2.o functions.o code_generator.o -o bfscript2 -no-pie

bfscript2.o: bfscript2.cpp functions.hpp includes.hpp code_generator.hpp color.hpp
	g++ -c bfscript2.cpp

functions.o: functions.cpp functions.hpp includes.hpp
	g++ -c functions.cpp

code_generator.o: code_generator.cpp code_generator.hpp includes.hpp
	g++ -c code_generator.cpp