CC = g++

CFLAGS = -std=c++17 -Wall -Wextra 

SRCS = $(wildcard *.h)
OBJS = $(SRCS:.cpp=.o)

NeuralNet: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.cpp %.h
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean