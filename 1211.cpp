#include <cstdio>
using namespace std;

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)

int main() {
	int test, n, cs = 1;
	int xa, xb, ya, yb, za, zb;
	int x1, x2, y1, y2, z1, z2;
	scanf("%d", &test);
	while(test--) {
		scanf("%d %d %d %d %d %d %d", &n, &xa, &ya, &za, &xb, &yb, &zb);
		for(n--; n--; ) {
			scanf("%d %d %d %d %d %d", &x1, &y1, &z1, &x2, &y2, &z2);
			xa = max(xa, x1), ya = max(ya, y1), za = max(za, z1);
			xb = min(xb, x2), yb = min(yb, y2), zb = min(zb, z2);
		}
		if(xa<=xb && ya<=yb && za<=zb) printf("Case %d: %d\n", cs++, (xb-xa)*(yb-ya)*(zb-za));
		else printf("Case %d: 0\n", cs++);
	}
	return 0;
}
