#include <cstdio>

int main() {
	int test, cs, n, i, a[11] = {2}, tot;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		for(i = 1; i <= n; i++) scanf("%d", &a[i]);
		for(tot = 0, i = 1; i <= n; i++) tot += (a[i]-a[i-1]+4)/5;
		printf("Case %d: %d\n", cs, tot);
	}
	return 0;
}
