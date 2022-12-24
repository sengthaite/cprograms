/*
* binary subtraction
*/

#include <stdio.h>
#include <stdlib.h>

// todo : -1 -1 = -10

void usage();
int len(char *num);
int len_arr(char **value);
char *gen_bin(char *num, int size);
char *subtract_two_number(char *first_number, char *second_number);
char *subtract(char **numbers);

int main(int argc, char **argv)
{
    if (argc <= 2)
    {
        usage();
        return 0;
    }

    char *argvs[len_arr(argv)];
    int i = 1;
    while(argv[i] != NULL)
    {
        argvs[i - 1] = argv[i];
        ++i;
    }
    argvs[i - 1] = NULL;

    printf("Result: %s\n", subtract(argvs));
    return 0;
}

void usage()
{
    printf("[Usage] binsub 1100 11 11\n");
}

char *gen_bin(char *num, int size)
{
    int num_len = len(num);
    if (num_len >= size)
        return num;
    char *result = malloc(size + 1);
    result[size] = '\0';
    while (size > 0)
    {
        if (num_len > 0)
        {
            result[size - 1] = num[num_len - 1];
            --num_len;
        }
        else
        {
            result[size - 1] = '0';
        }
        --size;
    }
    return result;
}

int len_arr(char **num)
{
    int i = 0;
    while(num[i] != NULL)
        ++i;
    return i;
}

int len(char *num)
{
    int i = 0;
    while (num[i] != '\0')
        ++i;
    return i;
}

char *subtract_two_number(char *first_number, char *second_number)
{
    int first_len = len(first_number), second_len = len(second_number);
    int max_len = first_len > second_len ? first_len : second_len;
    first_number = gen_bin(first_number, max_len);
    second_number = gen_bin(second_number, max_len);
    char *result = malloc((max_len + 2) * sizeof(char));
    result[max_len + 1] = '\0';

    char borrow = '0';
    while(max_len > 0)
    {
        char first_char = first_number[max_len - 1];
        char second_char = second_number[max_len - 1];
        if (first_char > '1' || first_char < '0' || second_char > '1' || second_char < '0')
            return NULL;

        int sub = first_char - second_char - borrow + '0';
        switch (sub) {
            case -2:
            case -1:
                result[max_len] = '1';
                borrow = '1';
                break;
            case 0:
                result[max_len] = '0';
                borrow = '0';
                break;
            case 1:
                result[max_len] = '1';
                borrow = '0';
                break;
            default:
                return NULL;
        }
        --max_len;
    }
    result[max_len] = borrow == '0' ? '0' : '-';
    return result;
}

char *subtract(char **numbers)
{
    int len_nums = len_arr(numbers);
    if (len_nums == 0)
        return numbers[0];
    char *result = "0";
    int i = 0;
    while(numbers[i + 1] != NULL)
    {
        result = subtract_two_number(numbers[i], numbers[i + 1]);
        ++i;
    }
    return result;
}