#Hyunjin Kang, Lab 106

CXX=clang++ $(CXXFLAGS)

AVLTree: AVLNode.o AVLTree.o AVLPathTest.o
	$(CXX) AVLNode.o AVLTree.o AVLPathTest.o

AVLNode.o: AVLNode.cpp AVLNode.h

AVLPathTest.o: AVLPathTest.cpp AVLTree.h AVLNode.h

AVLTree.o: AVLTree.cpp AVLNode.h AVLTree.h

.PHONY: clean
clean:
	-rm -f *.0 *~a.out
