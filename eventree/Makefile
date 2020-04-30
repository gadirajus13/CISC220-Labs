#Sohan Gadiraju
even: eventree.o
	g++ eventree.o -o even
 
eventree.o: eventree.cpp
	g++ -c eventree.cpp -std=c++11
 
run: even
	./even
 
clean:
	rm *.o even