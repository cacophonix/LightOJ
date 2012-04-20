#include <cstdio>

int main() {
	int test, cs, xsum, n, i, a[100], b[100];
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		for(i = 0; i < n; i++) scanf("%d", a + i);
		for(i = 0; i < n; i++) scanf("%d", b + i);
		for(xsum = i = 0; i < n; i++) xsum ^= (b[i]-a[i]-1);
		if(xsum) printf("Case %d: white wins\n", cs);
		else printf("Case %d: black wins\n", cs);
	}
	return 0;
}
