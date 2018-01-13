CXX = g++
TARGET = example
CXXFLAGS = -Wall -O2 -Wextra -std=c++11 -I.
SRCS = example.cpp

OBJS := $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $(OBJS)

clean:
	rm -f $(TARGET) $(OBJS)
