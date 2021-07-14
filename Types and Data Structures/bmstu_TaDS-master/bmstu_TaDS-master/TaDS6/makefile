CC = gcc
CFLAGS = -std=c99 -g3

app.exe: efficiency.o hash.o main.o tree.o
	$(CC) -o $@ $^
	
efficiency.o: efficiency.c 
	$(CC) $(CFLAGS) -c $<
	
hash.o: hash.c 
	$(CC) $(CFLAGS) -c $<
	
main.o: main.c
	$(CC) $(CFLAGS) -c $<
	
tree.o: tree.c
	$(CC) $(CFLAGS) -c $<
	
clean: 
	$(RM) *.exe *.o