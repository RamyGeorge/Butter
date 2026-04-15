CC = gcc
CFLAGS = -Wall -g -I./src

SRC = $(wildcard src/LL_utilities/*.c)
TEST = $(wildcard tests/*.c)

OUT = test_results

all: $(OUT)

$(OUT): $(SRC) $(TEST)
	$(CC) $(CFLAGS) $^ -o $@

test: $(OUT)
	./$(OUT)

clean:
	rm -f $(OUT)