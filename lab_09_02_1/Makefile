all: app.exe test.exe

app.exe:
	gcc -Wall -Werror -pedantic -std=c99 main.c main_processing.c lib.c -o app.exe

test.exe:
	gcc -Wall -Werror -pedantic -std=c99 test.c main_processing.c lib.c -o test.exe