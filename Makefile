CC = g++ -std=c++11 -g -Wall

exe_file = linked_list_imp

$(exe_file): driver.o linked_list.o node.o
	$(CC) driver.o linked_list.o node.o -o $(exe_file)
driver.o: driver.cpp
	$(CC) -c driver.cpp
linked_list.o: linked_list.cpp
	$(CC) -c linked_list.cpp
node.o: node.cpp
	$(CC) -c node.cpp

clean: 
	rm -f *.out *.o

.PHONY: clean