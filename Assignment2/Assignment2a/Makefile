CXX = g++
CXXFLAGS = -std=c++17 -Wall
TARGET = assignment2a
SRCS = assignment2a.cpp

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET) output.txt
	echo -n > source.txt

.PHONY: all clean
