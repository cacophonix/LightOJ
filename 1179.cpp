#include <cstdio>

int main() {
	int test, cs, i, n, k;
	long long int ans;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &n, &k);
		for(ans = 0, i = 2; i <= n; i++) {
			ans += k;
			if(ans >= i) ans %= i;
		}
		printf("Case %d: %lld\n", cs, ans + 1);
	}
	return 0;
}
