all: main.cpp SLINK.cpp Utils.cpp SingleLinkage.cpp
	g++ -std=c++14 -o main main.cpp SLINK.cpp SingleLinkage.cpp Utils.cpp -O2