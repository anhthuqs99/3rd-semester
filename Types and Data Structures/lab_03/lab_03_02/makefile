CC = gcc
CFLAGS = -std=c99 -g3

app.exe: input.o output.o alloc.o matrices.o time_testing.o main.o
	$(CC) -o $@ $^
input.o: input.c 
	$(CC) $(CFLAGS) -c $<
output.o: output.c
	$(CC) $(CFLAGS) -c $<
alloc.o: alloc.c
	$(CC) $(CFLAGS) -c $<
matrices.o: matrices.c
	$(CC) $(CFLAGS) -c $<
time_testing.o: time_testing.c
	$(CC) $(CFLAGS) -c $<
main.o: main.c
	$(CC) $(CFLAGS) -c $<
	
clean:
	$(RM) *.exe *.o
