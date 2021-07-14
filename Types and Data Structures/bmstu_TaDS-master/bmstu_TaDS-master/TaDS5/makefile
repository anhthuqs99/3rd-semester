CC = gcc
CFLAGS = -std=c99 -g3

app.exe: io.o list.o main.o q_array.o structures.o
	$(CC) -o $@ $^

io.o: io.c
	$(CC) $(CFLAGS) -c $<

list.o: list.c
	$(CC) $(CFLAGS) -c $<

main.o: main.c 
	$(CC) $(CFLAGS) -c $<
	
q_array.o: q_array.c 
	$(CC) $(CFLAGS) -c $<
	
structures.o: structures.c
	$(CC) $(CFLAGS) -c $<
	
clean:
	$(RM) *.exe *.o