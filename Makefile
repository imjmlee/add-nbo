CC = gcc
CFLAGS = -Wall -Wextra

all: add-nbo

add-nbo: add_nbo.c
	$(CC) $(CFLAGS) -o add-nbo add_nbo.c

clean:
	rm -f add-nbo

