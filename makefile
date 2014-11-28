CC = g++
OBJ = driver.o
OBJ2 = memory.o


prog: $(OBJ) $(OBJ2)
	$(CC) $(OBJ) $(OBJ2) -o $@

.cpp.o:
	$(CC) -c $<

clean:
	rm *.o prog
	
