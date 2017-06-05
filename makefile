CC = gcc
CFLAGS = -g -Wall
OBJ = tp0.o TAD.o
DEPS = TAD.h
EXECU = ./exec imagem_cena.pgm imagem_objeto.pgm imagem_saida.txt
FLAGS = --leak-check=full --leak-resolution=high --show-reachable=yes --track-origins=yes

all: exec

exec: $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f exec *.o

teste:
	$(EXECU)

val:
	valgrind $(FLAGS) $(EXECU)
