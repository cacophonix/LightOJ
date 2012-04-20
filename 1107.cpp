#include <cstdio>

int main() {
	int q, test, cs, x1, y1, x2, y2, x3, y3;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		printf("Case %d:\n", cs);
		scanf("%d", &q);
		while(q--) {
			scanf("%d %d", &x3, &y3);
			if(x1 <= x3 && x3 <= x2 && y1 <= y3 && y3 <= y2) puts("Yes");
			else puts("No");
		}
	}
	return 0;
}
