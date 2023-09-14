#Hyunjin Kang, Lab 106

CXX=clang++ $(CXXFLAGS)

TreeCalc: TreeCalcTest.o TreeCalc.o TreeNode.o
	$(CXX) TreeCalcTest.o TreeCalc.o TreeNode.o -o a.out

TreeCalc.o: TreeCalc.cpp TreeCalc.h TreeNode.h

TreeCalcTest.o: TreeCalcTest.cpp TreeCalc.h TreeNode.h

TreeNode.o: TreeNode.cpp TreeNode.h

.PHONY: clean
clean:
	-rm -f *.o *~a.out
