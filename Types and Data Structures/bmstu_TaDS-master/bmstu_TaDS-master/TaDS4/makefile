CC = gcc
CFLAGS = -std=c99 -g3

app.exe: main.o analysis.o array_stack.o parentheses.o list_stack.o
	$(CC) -o $@ $^
	
analysis.o: analysis.c
	$(CC) $(CFLAGS) -c $<
	
array_stack.o: array_stack.c
	$(CC) $(CFLAGS) -c $<
	
parentheses.o: parentheses.c
	$(CC) $(CFLAGS) -c $<
	
main.o: main.c
	$(CC) $(CFLAGS) -c $<
	
list_stack.o: list_stack.c
	$(CC) $(CFLAGS) -c $<
	
clean:
	$(RM) *.exe *.o