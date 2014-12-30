CC = gcc
EXE = ./cape
SRC = src/cape.c src/y.tab.c src/node.c src/lex.c src/vm.c src/console-colors.c
CFLAGS =
OBJS := cape.o y.tab.o node.o lex.o vm.o console-colors.o

all: $(OBJS)
	$(CC) -o $(EXE) $^

$(OBJS): $(SRC)
	$(CC) $(CFLAGS) -c $^

.PHONY: clean bison

clean:
	rm -rf *.o *.exe $(EXE)

bison:
	cd src && bison parse.y && cd ..
