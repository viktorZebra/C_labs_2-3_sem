all: app.exe test.exe

app.exe:
	gcc -Wall -Werror -pedantic main.c my_snprintf.c -o app.exe

test.exe:
	gcc -Wall -Werror -pedantic test.c my_snprintf.c -o test.exe
    