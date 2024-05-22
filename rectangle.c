#include <stdio.h>

struct point {
	double x;
	double y;
};

struct rect {
	struct point top_left;
	struct point bottom_right;
};

int main(void)
{
	struct rect myrect = {
		{0, 0},
		{24, 12}
	};
	double area = (myrect.bottom_right.x - myrect.top_left.x) * (myrect.bottom_right.y - myrect.top_left.y);
	printf("area of rect is: %2f\n", area);
	return 0;
}
