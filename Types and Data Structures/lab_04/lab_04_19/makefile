CC = gcc
CFLAGS = -std=c99 -Wall -Werror

app.exe: main.o array.o list.o time_using.o
	$(CC) -o $@ $^
	
main.o: main.c app.h
	$(CC) $(CFLAGS) -c $<

array.o: array.c array.h
	$(CC) $(CFLAGS) -c $<

list.o: list.c list.h
	$(CC) $(CFLAGS) -c $<
	
time_using.o: time_using.c time_using.h
	$(CC) $(CFLAGS) -c $<
	
clean: 
	$(RM) *.exe *.o