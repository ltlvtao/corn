MAKE = make
CFLAGS = -g -O3 -Wall
ARFLAGS = -rv

ifeq ($(shell uname), Linux)
	CC = gcc
	RM = rm
	RMFLAGS = -f
endif

ifeq ($(shell uname), Darwin)
	CC = clang
	RM = rm
	RMFLAGS = -f
endif

ifeq ($(INCLUDE),)
all:
	$(MAKE) -C src $@

clean:
	$(MAKE) -C src $@

endif
