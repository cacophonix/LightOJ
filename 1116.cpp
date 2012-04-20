#include <cstdio>

int main() {
	int test, cs;
	long long n, a;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%lld", &n); a = 1;
		while(!(n&1)) a <<= 1, n >>= 1;
		if(a & 1) printf("Case %d: Impossible\n", cs);
		else printf("Case %d: %lld %lld\n", cs, n, a);
	}
	return 0;
}
