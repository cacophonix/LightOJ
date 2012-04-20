#include <cstdio>

typedef long long i64;

int main() {
	int test, cs, r, c, i, j;
	i64 bucket[55], v, xsum;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &r, &c);
		for(i = 0; i < r; i++) {
			for(bucket[i] = j = 0; j < c; j++) {
				scanf("%lld", &v);
				bucket[i] += v;
			}
		}
		for(xsum = i = 0; i < r; i++) xsum ^= bucket[i];
		if(xsum) printf("Case %d: Alice\n", cs);
		else printf("Case %d: Bob\n", cs);
	}
	return 0;
}
