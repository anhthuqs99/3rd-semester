CC = gcc
CFLAGS = -std=c99 -g3

app.exe: io.o main.o add_del.o sort.o find.o
	$(CC) -o $@ $^

io.o: io.c io.h
	$(CC) $(CFLAGS) -c $<
	
main.o: main.c app.h
	$(CC) $(CFLAGS) -c $<
	
add_del.o: add_del.c add_del.h
	$(CC) $(CFLAGS) -c $<
	
sort.o: sort.c sort.h
	$(CC) $(CFLAGS) -c $<
	
find.o: find.c find.h
	$(CC) $(CFLAGS) -c $<
	
clean:
	$(RM) *o *.exe