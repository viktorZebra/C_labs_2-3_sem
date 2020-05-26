#include <stdio.h>
#include <stdlib.h>

#define SIZE_GROUP 10
#define NOT_CHANGE -1
#define OK 0
#define ERROR 1

typedef struct
{
    char name[30];
    int marks[3];
    float av_marks;
}Student;

float average(Student *students, int i);
void puts_average(Student *students, int count);
void delete_stupid_students(Student *students, int *count);
int min_ind(Student *students, int count, float buf_group_av);
void writeStudents(Student *students, FILE *f, int count);
void readStudents(Student *students, FILE *f, int count);
int countStudents(FILE *f);

int main()
{
	int out = OK;
	Student students[30];
	
	int choice;
	puts("What you want: write to file(1) / process file(2)?");
	scanf("%d", &choice);
	if (choice == 1)
	{
		FILE *f = fopen("in.bin", "wb");
		writeStudents(students, f, SIZE_GROUP);
		fclose(f);
	}
	
	else if (choice == 2)
	{
		
	
		FILE *f = fopen("in.bin", "rb");
		
		if (f)
		{
			int count = countStudents(f);
			readStudents(students, f, count);
			
			puts_average(students, count);
			delete_stupid_students(students, &count);
			fclose(f);
			
			FILE *f = fopen("in.bin", "wb");
			writeStudents(students, f, count);
			fclose(f);
		}
		else
			out = ERROR;
	}
	
	else
	{
		puts("Error :(((");
		out = ERROR;
	}
	
    return out;
}


float average(Student *students, int i)
{
    return (float)(students[i].marks[0] + students[i].marks[1] + students[i].marks[2]) / (float)3;
}

float group_average(Student *students, int count)
{
    float av = 0;
    for (int i = 0; i < count; i++)
        av += average(students, i);

    return av / (float)count;
}

void puts_average(Student *students, int count)
{
    for (int i = 0; i < count; i++)
        students[i].av_marks = average(students, i);
}

void delete_stupid_students(Student *students, int *count)
{
    float buf_group_av = group_average(students, *count);
    for (int i = 0; i < 2; i++)
        {
            int flag = 0;
            int min_indx = min_ind(students, *count, buf_group_av); // нахожу индекс ученика, у которого средний балл меньше всего
            for (int j = min_indx; min_indx != NOT_CHANGE && j < *count - 1; j++) // первое выражение в условии проверяет, был ли найден такой ученик
            {
                students[j] = students[j + 1];
                flag = 1;
            }
            if (flag || min_indx == *count - 1) // второе условие проверяет ученика самого последнего в списке, т.к. цикл выше обрабатывает на одного меньше ученика
                (*count)--;
        }
}

int min_ind(Student *students, int count, float buf_group_av)
{
    int min_indx = NOT_CHANGE;
    for (int i = 0; i < count; i++)
        if (buf_group_av > average(students, i))
        {
            min_indx = i;
        }

    return min_indx;
}

void writeStudents(Student *students, FILE *f, int count)
{
	fwrite(students, sizeof(Student), count, f);
}

void readStudents(Student *students, FILE *f, int count)
{
	fread(students, sizeof(Student), count, f);
}

int countStudents(FILE *f)
{
	int count;
	Student buf;
	
	while(!feof(f))
	{
		fread(&buf, sizeof(Student), 1, f);
		count++;
	}
	
	return count;
}