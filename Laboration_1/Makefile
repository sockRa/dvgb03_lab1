lab1: driver.o menu.o FE_Functions.o BE_Functions.o
	gcc -Wall -ggdb -o lab1 driver.o menu.o FE_Functions.o BE_Functions.o -lm
driver.o: driver.c driver.h
	gcc -c -ggdb driver.c
menu.o: menu.c driver.h
	gcc -c -ggdb menu.c
FE_Functions.o: FE_Functions.c driver.h
	gcc -c -ggdb FE_Functions.c
BE_Functions.o: BE_Functions.c driver.h
	gcc -c -ggdb BE_Functions.c

clean:
	rm *.o