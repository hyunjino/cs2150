#Hyunjin Kang, Lab 106

CXX=clang++ $(CXXFLAGS)

BinarySearchTree: BinaryNode.o BinarySearchTree.o BSTPathTest.o
	$(CXX) BinaryNode.o BinarySearchTree.o BSTPathTest.o

BinaryNode.o: BinaryNode.cpp BinaryNode.h

BinarySearchTree.o: BinarySearchTree.cpp BinaryNode.h BinarySearchTree.h

BSTPathTest.o: BSTPathTest.cpp BinarySearchTree.h BinaryNode.h

.PHONY: clean
clean:
	-rm -f *.0 *~a.out
