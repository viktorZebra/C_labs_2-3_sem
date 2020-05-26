#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR -1
#define ARG_ERROR 53
#define OK 0
#define MAX_COUNT 10

typedef struct
{
    char product_name[31];
    char factory_name[16];
    unsigned int product_price;
    unsigned int quantity;
} product_t;

void sort_file(char *in_file_name, int *out, int count);
void put_product_by_pos(FILE *f, product_t *value, const int position);
product_t get_product_by_pos(FILE *f, const int position);
int count_val(char *file_name);
void input_in_outfile(char *in_file_name, char *out_file_name, int count, int *out);
void print_file(char *file_name, int count);
void input_infile(char *file_name);
void product_search(char *file_in, char *substr, int count, int *out);
void search_place_new_product(char *file_in, int *count, int *out);
void input_new_product(FILE *f, product_t *new_product, product_t *buf, int *count, int i);
void add_new_position(FILE *f, product_t *buf);
void swap(FILE *f, int i, int max_indx);

int main(int argc, char **argv)
{
    int out = OK;
	
    if (argc == 4 || argc == 3)
    {
		if (strcmp(argv[1], "sb") == OK)
		{
			int count = count_val(argv[2]);

			if (count)
			{
				sort_file(argv[2], &out, count);
				input_in_outfile(argv[2], argv[3], count, &out);
				
				if (out == OK)
					print_file(argv[3], count);
			}
			else
				out = ERROR;
		}
		else if (strcmp(argv[1], "fb") == OK)
		{
			int count = count_val(argv[2]);

			if (count)
				product_search(argv[2], argv[3], count, &out);
			else
				out = ERROR;
		}
		else if (strcmp(argv[1], "ab") == OK)
		{
			int count = count_val(argv[2]);

			if (count)
			{
				search_place_new_product(argv[2], &count, &out);
			}
			else
				out = ERROR;
		}
		else
			out = ARG_ERROR;
    }
    else
        out = ERROR;

    return out;
}

int count_val(char *file_name)
{
    int count = 0;
    FILE *f = fopen(file_name, "rb");
    if (f)
    {
        fseek(f, 0, SEEK_END);
        count = ftell(f) / sizeof(product_t);
        fclose(f);
    }

    return count;
}


void sort_file(char *in_file_name, int *out, int count)
{
    int ind_max = 0;
    product_t a, b;
    memset(&a, 0, sizeof(product_t));
    memset(&b, 0, sizeof(product_t));

    FILE *f_in = fopen(in_file_name, "r + b");

    if (f_in)
    {
        for (int i = 0; i < count - 1; i++)
        {
            ind_max = i;

            for (int j = i + 1; j < count; j++)
            {
                a = get_product_by_pos(f_in, ind_max);
                b = get_product_by_pos(f_in, j);

                if ((a.product_price < b.product_price) || (a.product_price == b.product_price && a.quantity < b.quantity))
                    ind_max = j;
            }

            a = get_product_by_pos(f_in, ind_max);
            b = get_product_by_pos(f_in, i);
            put_product_by_pos(f_in, &a, i);
            put_product_by_pos(f_in, &b, ind_max);
        }
		
        fclose(f_in);
    }
    else
        *out = ERROR;
}

product_t get_product_by_pos(FILE *f, const int position)
{
    product_t value;
    memset(&value, 0, sizeof(product_t));

    int pos = ftell(f);

    fseek(f, position * sizeof(product_t), SEEK_SET);
    fread(&value, sizeof(product_t), 1, f);

    fseek(f, pos, SEEK_SET);

    return value;
}

void put_product_by_pos(FILE *f, product_t *value, const int position)
{
    int pos = ftell(f);

    fseek(f, position * sizeof(product_t), SEEK_SET);
    fwrite(value, sizeof(product_t), 1, f);

    fseek(f, pos, SEEK_SET);
}

void input_in_outfile(char *in_file_name, char *out_file_name, int count, int *out)
{
    product_t buf;
    memset(&buf, 0, sizeof(product_t));

    FILE *f_in = fopen(in_file_name, "rb");
    FILE *f_out = fopen(out_file_name, "wb");
    
    if (f_out)
    {
        for (int i = 0; i < count; i++)
        {
            fread(&buf, sizeof(product_t), 1, f_in);
            fwrite(&buf, sizeof(product_t), 1, f_out);
        }
		
        fclose(f_in);
        fclose(f_out);
    }
    else
        (*out) = ERROR;
}
void print_file(char *file_name, int count)
{
    FILE *f = fopen(file_name, "rb");
    for (int i = 0; i < count; i++)
    {
        product_t buf;
        memset(&buf, 0, sizeof(product_t));
        fread(&buf, sizeof(product_t), 1, f);
        printf("%s\n%s\n%u\n%u\n", buf.product_name, buf.factory_name, buf.product_price, buf.quantity);
    }
    fclose(f);
}

void input_infile(char *file_name)
{
    FILE *f = fopen(file_name, "wb");
    for (int i = 0; i < 3; i++)
    {
        product_t buf;
        memset(&buf, 0, sizeof(product_t));
        scanf("%s", buf.product_name);
        scanf("%s", buf.factory_name);
        scanf("%u", &buf.product_price);
        scanf("%u", &buf.quantity);
        fwrite(&buf, sizeof(product_t), 1, f);
    }
    fclose(f);
}

void product_search(char *in_file_name, char *substr, int count, int *out)
{
    FILE *f = fopen(in_file_name, "rb");
    product_t value;
    memset(&value, 0, sizeof(product_t));
    int len_substr = strlen(substr);
    int flag = 1;

    for (int i = 0; i < count; i ++)
    {
        fread(&value, sizeof(product_t), 1, f);

        int check_count = 0;
        int len_name = strlen(value.product_name) - 1;
        int k = len_substr - 1;

        for (int j = len_name; j >= 0 && k >= 0; j--, k--)
        {
            if (value.product_name[j] == substr[k])
                check_count++;
        }
        if (check_count == len_substr)
        {
            printf("%s\n%s\n%u\n%u\n", value.product_name, value.factory_name, value.product_price, value.quantity);
            flag = 0;
        }
    }

    if (flag)
        *out = ERROR;

    fclose(f);
}

void search_place_new_product(char *file_in, int *count, int *out)
{
    FILE *f = fopen(file_in, "r + b");

    if (f)
    {
        int flag = 1;

        product_t buf;
        product_t new_product;
        memset(&buf, 0, sizeof(product_t));
        memset(&new_product, 0, sizeof(product_t));

        puts("Input new product:\n");
        scanf("%s", new_product.product_name);
        scanf("%s", new_product.factory_name);
        scanf("%u", &new_product.product_price);
        scanf("%u", &new_product.quantity);

        for (int i = 0; flag && i < *count; i++)
        {
            buf = get_product_by_pos(f, i);

            if ((new_product.product_price > buf.product_price) || (new_product.product_price == buf.product_price && buf.quantity < new_product.quantity))
            {
                flag = 0;
                add_new_position(f, &buf);
                input_new_product(f, &new_product, &buf, count, i);
            }
        }

        if (flag)
        {
            (*count)++;
            fseek(f, 0, SEEK_END);
            fwrite(&new_product, sizeof(product_t), 1, f);
        }
		
        fclose(f);
    }
    else
        *out = ERROR;
}

void input_new_product(FILE *f, product_t *new_product, product_t *buf, int *count, int i)
{
    (*count)++;

    for (int j = *count - 1; j > i; j--)
    {
        (*buf) = get_product_by_pos(f, j - 1);
        put_product_by_pos(f, buf, j);
    }

    put_product_by_pos(f, new_product, i);
}

void add_new_position(FILE *f, product_t *buf)
{
    int pos = ftell(f);
    fseek(f, 0, SEEK_END);
    fwrite(buf, sizeof(product_t), 1, f);
    fseek(f, pos, SEEK_SET);
}

void swap(FILE *f_in, int i, int ind_max)
{
    product_t a = get_product_by_pos(f_in, ind_max);
    product_t b = get_product_by_pos(f_in, i);
    put_product_by_pos(f_in, &a, i);
    put_product_by_pos(f_in, &b, ind_max);
}

