CC := g++
CXXFLAGS += -std=c++11
SRC := $(wildcard *.cpp)
EXE := $(patsubst %.cpp, %.exe, $(SRC))

all: $(EXE)

%.exe: %.cpp
	$(CC) $(CXXFLAGS) $< -o $@

clean:
	cmd /C del *.exe
