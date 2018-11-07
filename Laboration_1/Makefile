lab1: driver.o menu.o FE_Functions.o BE_Functions.o
	gcc -Wall -o lab1 driver.o menu.o FE_Functions.o BE_Functions.o
driver.o: driver.c driver.h
	gcc -c driver.c
menu.o: menu.c driver.h
	gcc -c menu.c
FE_Functions.o: FE_Functions.c driver.h
	gcc -c FE_Functions.c
BE_Functions.o: BE_Functions.c driver.h
	gcc -c BE_Functions.c

clean:
	rm *.o