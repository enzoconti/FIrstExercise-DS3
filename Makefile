all:
	gcc -c ./source/IOFile.c -I ./header -o ./obj/IOFile.o
	gcc -c ./source/readFunctionality.c -I ./header -o ./obj/readFunctionality.o
	gcc -c ./source/writeFunctionality.c -I ./header -o ./obj/writeFunctionality.o

	gcc ./source/main.c ./obj/*.o -I ./header -o ./bin/main

run:
	./bin/main

clean:
	rm ./obj/*.o
	rm ./bin/*