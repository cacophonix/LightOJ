#include <cstdio>

typedef struct { int x, y; } Point;

int main() {
	Point a, b, c, d, m;
	int test, cs, area;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d %d %d %d %d", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y);
		m.x = a.x + c.x;
		m.y = a.y + c.y;
		d.x = m.x - b.x;
		d.y = m.y - b.y;
		area = a.x * b.y - a.y * b.x;
		area += b.x * c.y - b.y * c.x;
		area += c.x * d.y - c.y * d.x;
		area += d.x * a.y - d.y * a.x;
		if(area < 0) area = -area;
		printf("Case %d: %d %d %d\n", cs, d.x, d.y, area >> 1);
	}
	return 0;
}
