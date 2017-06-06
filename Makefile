all: main.cpp SLINK.cpp Utils.cpp SingleLinkage.cpp
	g++ -std=c++11 -o main main.cpp SLINK.cpp SingleLinkage.cpp Utils.cpp