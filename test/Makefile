INCLUDE = ../Makefile
include $(INCLUDE)
CFLAGS += -I../include
LDFLAGS += -L../src

all:test-micron

test-micron:test-micron.o
	$(CC) $(LDFLAGS) -o $@ $^ -lmicron

clean:
	$(RM) $(RMFLAGS) test-micron test-micron.o