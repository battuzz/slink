all: main.cpp SLINK.cpp Utils.cpp SingleLinkage.cpp
	g++ -o main main.cpp SLINK.cpp SingleLinkage.cpp Utils.cpp