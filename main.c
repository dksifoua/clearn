#include <stdio.h>

typedef struct point {
  int x, y;
} Point;

int distance(Point p1, Point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int main(void) {
  int x1, y1, x2, y2;
  scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
  Point p1 = {.x = x1, .y = y1};
  Point p2 = {.x = x2, .y = y2};

  printf("%d\n", distance(p1, p2));
  return 0;
}
