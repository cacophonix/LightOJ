#include <cstdio>

int main() {
	int test, cs, x, y;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &x, &y);
		if(x == 1 || y == 1) printf("Case %d: %d\n", cs, x + y - 1);
		else if(x == 2 || y == 2) printf("Case %d: %d\n", cs, (((((x==2?y:x)-1)>>2)<<1) + 1 + !!(((x==2?y:x)-1)&3))<<1);
		else printf("Case %d: %d\n", cs, (x*y + 1)>>1);
	}
	return 0;
}
