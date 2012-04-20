#include <cstdio>

#define _max(a, b) (a>b?a:b)

int main() {
	int test, cs = 1, a[2][10001], n, v, i, j;
	scanf("%d", &test);
	while(test--) {
		scanf("%d", &n);
		a[0][0] = a[0][1] = 0;
		for(i = 1; i <= n; i++) {
			for(j = 1; j <= i; j++) {
				scanf("%d", &v);
				a[i&1][j] = _max(a[(i-1)&1][j-1], a[(i-1)&1][j]) + v;
			}
			a[i&1][j] = 0;
		}
		for(i = n-1; i; i--) {
			for(j = 1; j <= i; j++) {
				scanf("%d", &v);
				a[i&1][j] = _max(a[(i-1)&1][j], a[(i-1)&1][j+1]) + v;
			}
		}
		printf("Case %d: %d\n", cs++, a[(i+1)&1][1]);
	}
	return 0;
}
