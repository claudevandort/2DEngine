CXX = g++
CXXFLAGS = -std=c++17 -Wall -I/opt/homebrew/include -I/opt/homebrew/opt/lua/include/lua -I"./libs/" -L/opt/homebrew/lib
LDLIBS = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -llua5.4
SOURCE = src/*.cpp
OUTPUT = engine

build:
	$(CXX) $(CXXFLAGS) $(SOURCE) -o $(OUTPUT) $(LDLIBS)

run:
	./$(OUTPUT)

clean:
	rm $(OUTPUT)
