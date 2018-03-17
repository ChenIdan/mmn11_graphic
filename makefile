CC=gcc
ELIB= -lGL -lglut -lGLU -lGLEW -lm 
CFLAGS= -Wall -g -ansi 

mmn11: mmn11.o 
		$(CC) $(CFLAGS) -o mmn11  mmn11.o $(ELIB) 
		
		

mmn11.o: mmn11.c
		$(CC) $(CFLAGS) -c mmn11.c $(ELIB) 
		
clean:
	rm -f *.o