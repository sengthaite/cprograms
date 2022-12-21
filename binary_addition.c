/*
 * binary addition
 */

#include <stdio.h>
#include <stdlib.h>

void usage();
int len(char *num);
int len_arr(char **value);
char *gen_bin(char *num, int size);
char *sum_two_value(char *first_number, char *second_number);
char *sum(char **num);

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

    printf("Result: %s\n", sum(argvs));
    return 0;
}

void usage()
{
    printf("./binadd 111011 111000\n");
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

char *sum_two_value(char *first_number, char *second_number)
{
    int first_len = len(first_number), second_len = len(second_number);
    int max_len = first_len > second_len ? first_len : second_len;
    char *longer_num = first_len > second_len ? first_number : second_number;
    char *shorter_num = gen_bin(first_len > second_len ? second_number : first_number, max_len);
    char *result = malloc((max_len + 2) * sizeof(char));
    result[max_len + 1] = '\0';

    char carry = '0';
    while (max_len > 0)
    {
        char long_char = longer_num[max_len - 1];
        char short_char = shorter_num[max_len - 1];
        if (long_char > '1' || long_char < '0' || short_char > '1' || short_char < '0')
            return NULL;
        int sum = long_char + short_char + carry - '0' - '0' - '0';
        switch (sum)
        {
        case 0:
            result[max_len] = '0';
            break;
        case 1:
            result[max_len] = '1';
            carry = '0';
            break;
        case 2:
            result[max_len] = '0';
            carry = '1';
            break;
        case 3:
            result[max_len] = '1';
            carry = '1';
            break;
        default:
            return NULL;
        }
        --max_len;
    }
    result[max_len] = carry;
    return result;
}

char *sum(char **num)
{
    char *result = "0";
    int i = 0;
    while(num[i] != NULL)
    {
        result = sum_two_value(result, num[i]);
        ++i;
    }
    return result;
}