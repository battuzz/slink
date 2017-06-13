#all: main.cpp SLINK.cpp Utils.cpp SingleLinkage.cpp
#	g++ -std=c++14 -o main main.cpp SLINK.cpp SingleLinkage.cpp Utils.cpp -O2

 
CC := g++ # This is the main compiler
# CC := clang --analyze # and comment out the linker last line for sanity
SRCDIR := src
BUILDDIR := build
TARGET := bin/slink
 
SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name "*.$(SRCEXT)")
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -std=c++14 -O2 # -Wall
LIB := #-pthread -lmongoclient -L lib -lboost_thread-mt -lboost_filesystem-mt -lboost_system-mt
INC := -I include

all: $(TARGET) single_linkage SLINK single_linkage_optimized

$(TARGET): $(OBJECTS)
	@echo " Linking..."
	@echo " $(CC) $^ -o $(TARGET) $(LIB)"; $(CC) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

single_linkage: build/Utils.o build/SingleLinkage.o
	$(CC) $(CFLAGS) build/Utils.o build/SingleLinkage.o test/run_single_linkage.cpp $(INC) $(LIB) -o bin/run_single_linkage

SLINK: build/Utils.o build/SLINK.o
	$(CC) $(CFLAGS) build/Utils.o build/SLINK.o test/run_slink.cpp $(INC) $(LIB) -o bin/run_slink

single_linkage_optimized: build/Utils.o build/SingleLinkageOptimized.o
	$(CC) $(CFLAGS) build/Utils.o build/SingleLinkageOptimized.o test/run_single_linkage_optimized.cpp $(INC) $(LIB) -o bin/run_single_linkage_optimized

clean:
	@echo " Cleaning..."; 
	@echo " $(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)

.PHONY: clean