.PHONY: all

SOURCES = main.cpp
OBJECTS = $(SOURCES:.cpp=.o)

CXX = g++
CXXFLAGS = 
CXX_LDFLAGS =

all: appAA

clean:
	rm ./*.o

appAA: $(OBJECTS)
	$(CXX) $(CXX_LDFLAGS) $(CXXFLAGS) $(OBJECTS) -o appAA 

main.o:
	$(CXX) -c src/main.cpp -o main.o $(CXXFLAGS)

Noeud.o:
	$(CXX) -c src/Noeud.cpp -o Noeud.o $(CXXFLAGS)

Racine.o:
	$(CXX) -c src/Racine.cpp -o Racine.o $(CXXFLAGS)

BArbre.o:
	$(CXX) -c src/BArbre.cpp -o BArbre.o $(CXXFLAGS)
