CXX = g++
TARGET = example
CXXFLAGS = -Wall -O2 -Wextra -std=c++11 -I.
LDLIBS = -lpthread
SRCS = example.cpp

OBJS := $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDLIBS)

clean:
	rm -f $(TARGET) $(OBJS)
