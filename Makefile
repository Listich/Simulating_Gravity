CXX = g++

CXXFLAGS = -Wall -Wextra -std=c++17 -O2 -Isrc/header

TARGET = Gravity

SRCS = $(shell find src -name "*.cpp")
OBJS = $(SRCS:.cpp=.o)


all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean re