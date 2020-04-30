brick: brickwall.o
	g++ brickwall.o -o brick
 
brickwall.o: brickwall.cpp
	g++ -c brickwall.cpp -std=c++11
 
run: brick
	./brick
 
clean:
	rm *.o brick
