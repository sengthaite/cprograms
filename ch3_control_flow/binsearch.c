#include <stdio.h>

int len_arr(int v[]);
int binsearch(int x, int v[]); // v[] must be sorted array

int main()
{

    int value[] = {1, 2, 10, 23, 56, 128, 129};
    printf("Binsearch for 129 found at index: %d\n", binsearch(129, value));
    return 0;
}

int len_arr(int v[])
{
    int i = 0;
    while(v[i] != '\0')
        ++i;
    return i;
}

int binsearch(int x, int v[])
{
    int lower_index, higher_index;
    lower_index = 0;
    higher_index = len_arr(v) - 1;
    while(lower_index != higher_index)
    {
        int mid = (lower_index + higher_index) * 0.5;
        x > v[mid] ? (lower_index = mid + 1) : (higher_index = mid);
    }
    return v[lower_index] == x ? lower_index : -1;
}
