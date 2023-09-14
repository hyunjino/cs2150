#Hyunjin Kang, lab 106

CXXFLAGS=-O2
CXX=clang++ $(CXXFLAGS)

wordPuzzle: wordPuzzle.o hashTable.o timer.o
	$(CXX) wordPuzzle.o hashTable.o timer.o

hashTable.o: hashTable.cpp hashTable.h

wordPuzzle.o: wordPuzzle.cpp hashTable.h

timer.o: timer.cpp timer.h

.PHONY: clean
clean:
	-rm -f *.0 *~a.out
