export CC = gcc
export CPPFLAGS = -Isrc
export CFLAGS = -std=c99 -Werror -Wall -Wextra -Wvla -pedantic

BINARY=httpd

all: $(BINARY)


testmac: test/fist_test.c
    gcc $< -o $@ -I/opt/homebrew/include -L/opt/homebrew/lib -lcriterion


test: test.c
    gcc $< -o $@  -lcriterion


$(BINARY):
	$(MAKE) -C src
	mv src/$(BINARY) .

.PHONY: all
