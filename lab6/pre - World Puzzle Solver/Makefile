#Hyunjin Kang, lab 106

CXX=clang++ $(CXXFLAGS)

wordPuzzle: wordPuzzle.o hashTable.o
	$(CXX) wordPuzzle.o hashTable.o

hashTable.o: hashTable.cpp hashTable.h

wordPuzzle.o: wordPuzzle.cpp hashTable.h

.PHONY: clean
clean:
	-rm -f *.0 *~a.out
