CFLAGS = -Wall -Wextra -g

all:
	g++ $(CFLAGS) -o main main.cpp

decrypt: CFLAGS += -DDECRYPT
decrypt: all

clean:
	rm -f main
