#include <stdio.h>

struct point {
    int x;
    int y;
};

struct rect {
    struct point p1;
    struct point p2;
};

struct point makepoint(int x, int y);

int pointinrect(struct point p, struct rect r);

int main(void) {

    struct rect myrect;
    myrect.p1 = makepoint(0,0);
    myrect.p2 = makepoint(2, 2);

    int is_point_in_rect = pointinrect(makepoint(1, 1), myrect);

    printf("point is %s\n", is_point_in_rect ? "in rect" : "not in rect");
    return 0;
}

struct point makepoint(int x, int y) {
    struct point temp;

    temp.x = x;
    temp.y = y;
    return temp;
};

/* pinrect: return 1 if p in r, o if not */
int pointinrect(struct point p, struct rect r) {
    return p.x >= r.p1.x && p.x < r.p2.x && p.y >= r.p1.y && p.y < r.p2.y;
}
