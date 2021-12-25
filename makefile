hepsi: derle calistir
derle:
	g++ -I ./include -o ./lib/nokta.o -c ./src/nokta.cpp
	g++ -I ./include -o ./lib/dogrukuyrugu.o -c ./src/dogrukuyrugu.cpp
	g++ -I ./include -o ./bin/main ./lib/nokta.o ./lib/dogrukuyrugu.o ./src/main.cpp
calistir:
	./bin/main
	