CXX = g++

CXXFLAGS = -Wall -Wextra -std=c++17 -O2 -Isrc/header -I/opt/homebrew/include

LDFLAGS = -L/opt/homebrew/lib -lraylib -framework Cocoa -framework IOKit -framework CoreVideo -framework OpenGL

TARGET = Gravity

SRCS = $(shell find src -name "*.cpp")
OBJS = $(SRCS:.cpp=.o)


all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean re