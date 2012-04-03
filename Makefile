.PHONY: all

SOURCES = main.cpp
OBJECTS = $(SOURCES:.cpp=.o)

CXX = g++
CXXFLAGS =  -g 
CXX_LDFLAGS =

all: appAA

clean:
	rm ./*.o

appAA: $(OBJECTS)
	$(CXX) $(CXX_LDFLAGS) $(CXXFLAGS) $(OBJECTS) -o appAA 

main.o:
	$(CXX) -c src/main.cpp -o main.o $(CXXFLAGS)

