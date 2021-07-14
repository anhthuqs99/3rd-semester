CC = gcc
CFLAGS = -std=c99 -Wall -Werror -g3

app.exe: main.o tree.o time_testing.o hash.o
	$(CC) -o $@ $^
	
main.o: main.c app.h
	$(CC) $(CFLAGS) -c $<
	
tree.o: tree.c tree.h
	$(CC) $(CFLAGS) -c $<
	
time_testing.o: time_testing.c 
	$(CC) $(CFLAGS) -c $<
	
hash.o: hash.c app.h
	$(CC) $(CFLAGS) -c $<
	
clean:
	$(RM) *.exe *.o