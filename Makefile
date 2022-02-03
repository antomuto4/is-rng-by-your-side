app: text-adventure.o
	gcc text-adventure.o -o app
text-adventure.o: text-adventure.c
	gcc -c text-adventure.c
clean:
	rm *.o app
