hepsi: derle calistir
derle:
	g++ -I ./include -o ./lib/nokta.o -c ./src/nokta.cpp
	g++ -I ./include -o ./lib/dkgezici.o -c ./src/dkgezici.cpp
	g++ -I ./include -o ./lib/dogrukuyrugu.o -c ./src/dogrukuyrugu.cpp
	g++ -I ./include -o ./lib/dugum.o -c ./src/dugum.cpp
	g++ -I ./include -o ./lib/avl.o -c ./src/avl.cpp
	g++ -I ./include -o ./bin/main ./lib/dkgezici.o ./lib/avl.o ./lib/dugum.o ./lib/nokta.o ./lib/dogrukuyrugu.o ./src/main.cpp
calistir:
	./bin/main
	