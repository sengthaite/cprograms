/* 
1. serve for any data type (similar to generic)
2. in-line code look like function
3. to remove define macro use #undef
4. concat macro param with string
5. concat between macro params
*/

#define tobe_undef() "..."
#undef tobe_undef
void tobe_undef();

#define forever for(;;) // infinit loop
#define max(A, B) ((A) > (B) ? (A) : (B))

#include <stdio.h>

#define dprint(message) printf(#message " = %g\n", message)
#define make_num(first_part, second_part, third_part) first_part ##  second_part ## third_part
#define make_string(first_part, second_part) first_part     second_part

int main(void)
{
    printf("max of 10, 20 is %d\n", max(10, 20));
    // pitfalls of macro here: with incremental operator or input output
    int i = 1, j = 2;
    printf("max of i++, j++ is %d\n", max(i++, j++));
    dprint(10.0 / 2);
    printf("number = %d\n", make_num(1, 2, 3));
    printf("number %s\n", make_string("1", "2"));
    tobe_undef();
    return 0;
}

void tobe_undef() {
    printf("tobe_undef is a function not a macro\n");
}