struct point {
	int x;
	int y;
};

#include <stdio.h>

int main(void)
{
	struct point a = { 10, 2 };
	printf("x: %d, y: %d\n", a.x, a.y);
	return 0;
}
