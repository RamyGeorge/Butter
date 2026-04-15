CC = gcc
CFLAGS = -Wall -g -I./src

SRC = $(wildcard src/LL_utilities/*.c)
TESTLL = $(wildcard tests/ll/*.c)

OUTll = test_ll_res

all: $(OUTll)

$(OUTll): $(SRC) $(TESTLL)
	$(CC) $(CFLAGS) $^ -o $@

test_ll: $(OUTll)
	./$(OUTll)

clean:
	rm -f $(OUTll)