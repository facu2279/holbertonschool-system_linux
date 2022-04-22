# compiler: gcc
CC = gcc

# compiler flags
# -Wall
# -Werror
# -Wextra
# -pedantic
CFLAGS = -Wall -Werror -Wextra -pedantic
DEPS = syscalls.h strace.h

SRCS0 = strace_0.c
OBJ0 = $(SRCS0:.c=.o)

SRC1 = strace_1.c
OBJ1 = $(SRC1:.c=.o)

SRC2 = strace_2.c
OBJ2 = $(SRC2:.c=.o)

SRC3 = strace_3.c
OBJ3 = $(SRC3:.c=.o)

all: $(OBJ0)

strace_0: $(OBJ0)
	$(CC) $(CFLAGS) $(DEPS) $(OBJ0) -o strace_0

strace_1: $(OBJ1)
	$(CC) $(CFLAGS) $(DEPS) $(OBJ1) -o strace_1

strace_2: $(OBJ2)
	$(CC) $(CFLAGS) $(DEPS) $(OBJ2) -o strace_2

strace_3: $(OBJ3)
	$(CC) $(CFLAGS) $(DEPS) $(OBJ3) -o strace_3

clean:
	$(RM) *.o
	$(RM) *~
	$(RM) strace_0
	$(RM) strace_1
	$(RM) strace_2
	$(RM) strace_3
