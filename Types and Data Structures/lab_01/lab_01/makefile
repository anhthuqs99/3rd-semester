CC = gcc

CFLAGS = -std=c99 -g3

app.exe: main2.o
	$(CC) -o $@ $^
	
main2.o: main2.c
	$(CC) $(CFLAGS) -c $<

clean: 
	$(RM) *.exe *.o