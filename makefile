functions:	rps_functions.c
	gcc -c rps_functions.c -o rps.o

main:	main.c
	gcc -c main.c  -o main.o

rps:	main.o rps_functions.o
	gcc main.o rps.o -o rps.run
