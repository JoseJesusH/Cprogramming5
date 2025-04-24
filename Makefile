# Makefile - to compile the Set and Matrix ADT projects

CC = clang
CFLAGS = -Wall -Wextra -g

# Object files for Set  ADT
SET_OBJS = main_set.o set.o

# Object files for Matrix ADT
MATRIX_OBJS = main_matrix.o matrix.o

all: set matrix

set: $(SET_OBJS)
	$(CC) $(CFLAGS) -o set $(SET_OBJS)

matrix: $(MATRIX_OBJS)
	$(CC) $(CFLAGS) -o matrix $(MATRIX_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o set matrix

