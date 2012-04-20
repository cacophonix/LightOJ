#include <cstdio>

#define mod(n,m) (n<m?n:n%m)
#define MOD 10000007

int hexfib[10001];

int main() {
	int test, cs, i, j, n;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		for(i = 0; i < 6; i++) {
			scanf("%d", &hexfib[i]);
			hexfib[i] = mod(hexfib[i], MOD);
		}
		scanf("%d", &n);
		for(; i <= n; i++) {
			for(hexfib[i] = 0, j = 1; j < 7; j++) hexfib[i] += hexfib[i-j];
			hexfib[i] = mod(hexfib[i], MOD);
		}
		printf("Case %d: %d\n", cs, hexfib[n]);
	}
	return 0;
}
