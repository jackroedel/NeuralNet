CC = clang++
CFLAGS = -std=c++17 -Wall -Wextra 

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

NeuralNet: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.cpp %.h
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean

