#include <cstdio>

typedef long long i64;

int main() {
	int test, cs, i, lg;
	i64 n, res, full[32], tmp;
	full[0] = full[1] = 0;
	for(i = 2; i < 32; i++) full[i] = (full[i-1] << 1) + (1LL << (i - 2));
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%lld", &n);
		for(res = n, lg = 0; res > 0; lg++, res >>= 1);
		for(res = 0, i = lg; i > 1; i--) {
			if(n & (1LL << (i-1))) {
				res += full[i-1];
				tmp = (1LL << (i-1)) + (1LL << (i-2));
				if(tmp <= n) res += (n - tmp + 1);
				n -= (1LL << (i-1));
			}
		}
		printf("Case %d: %lld\n", cs, res);
	}
	return 0;
}