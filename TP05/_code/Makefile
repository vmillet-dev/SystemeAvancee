ALLSRC_C=$(wildcard *.c)
ALLCOMPILED_C=$(patsubst %.c,%.exe)
CFLAGS=-Wall

all: ex1.exe ex2.exe ex3.exe  # ajouter pour les courbes


%.exe : %.c
	gcc  $(CFLAGS) $< -o $@

clean:
	@rm -f *.exe *~ *.csv results_ex3.pdf
