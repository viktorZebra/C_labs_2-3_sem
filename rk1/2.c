//Вариант 3

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define OK 0
#define ERROR 1
#define MAX_SIZE 1000

double midleVal(int *array, int size);
void checkInput(int *array, int size, int *cursorOut);
void formingNewArray(int *array, int size, double midle, int *newArray, int *newSize);
void print(int *array, int size);

int main()
{
    int out = OK;
    int array[MAX_SIZE];
    int newArray[MAX_SIZE];
    int newSize = 0;
	
    int size;
    puts("input size");
    int rc1 = scanf("%d", &size);
	
    if (rc1 == 1)
    {
        checkInput(array, size, &out);
        
        if (out == OK)
        {
            double midle = midleVal(array, size);
            
            formingNewArray(array, size, midle, newArray, &newSize);
            
            print(newArray, newSize);
        }
    }
    else
        out = ERROR;
	
    return out;
}


void checkInput(int *array, int size, int *cursorOut)
{
    int rc;

    for (int i = 0; i < size; i++)
    {
        rc = scanf("%d", (array + i));

        if (rc != 1)
            *cursor_out = ERROR;
    }
}

double midleVal(int *array, int size)
{
	double midle;
	
	for (int i = 0; i < size; i++)
		midle += array[i] * array[i];
	
	midle = sqrt(midle/(double)size);
	
	return midle;
}

void formingNewArray(int *array, int size, double midle, int *newArray, int *newSize)
{
    for (int i = 0; i < size; i++)
	    {
		    if (array[i] > midle)
		    {
			    newArray[(*newSize)] = array[i];
			    (*newSize)++;
		    }
	    }
}


void print(int *array, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
}

