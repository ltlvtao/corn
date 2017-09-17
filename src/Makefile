INCLUDE = ../Makefile
include $(INCLUDE)
CFLAGS += -fPIC -I. -I../include

all: libmicron.a

libmicron.a: micron.o
	$(AR) $(ARFLAGS) $@ $^

clean:
	$(RM) $(RMFLAGS) *.o libmicron.a