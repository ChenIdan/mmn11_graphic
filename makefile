CC=gcc
ELIB= -lGL -lglut -lGLU -lGLEW  -lm 
CFLAGS= -Wall -g -ansi 




mmn11: mmn11.o 
		$(CC) $(CFLAGS) -o mmn11  mmn11.o -I/usr/include/freetype2 -lfreetype $(ELIB) 
		
		

mmn11.o: mmn11.c
		$(CC) $(CFLAGS) -c mmn11.c -I/usr/include/freetype2 -lfreetype $(ELIB) 
		
clean:
	rm -f *.o