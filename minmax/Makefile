# Nick Fafel and Sohan Gadiraju

it: iterative.o
	g++ iterative.o -o iterative

re: recursive.o
	g++ recursive.o -o recursive

iterative.o: iterative.cpp
	g++ -c iterative.cpp

recursive.o: recursive.cpp
	g++ -c recursive.cpp

run: iterative recursive
	./iterative
	./recursive

clean: 
	rm *.o iterative recursive
