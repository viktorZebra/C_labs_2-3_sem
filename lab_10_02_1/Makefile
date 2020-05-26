all: app.exe test.exe

app.exe:
	gcc -Wall -Werror -pedantic main.c main_processing.c sort_array_of_struct.c CDIO_array_of_struct.c add_and_delete.c -o app.exe

test.exe:
	gcc -Wall -Werror -pedantic test.c main_processing.c sort_array_of_struct.c CDIO_array_of_struct.c add_and_delete.c -o test.exe