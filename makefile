myps: myps.o options.o parse.o process.o
	gcc -o myps myps.o options.o parse.o process.o

myps.o: myps.c options.h parse.h process.h structs.h
	gcc -c myps.c -Wall -Werror

options.o: options.c 
	gcc -c options.c -Wall -Werror

parse.o: parse.c 
	gcc -c parse.c -Wall -Werror

process.o: process.c
	gcc -c process.c -Wall -Werror

clean: 
	rm -rf *.o mymyps