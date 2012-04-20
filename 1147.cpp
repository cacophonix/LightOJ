#include <cstdio>
#include <cstring>

typedef long long i64;

const int MAX = 50001;

i64 dp[MAX];

int main() {
	int test, cs, n, i, j, o, e, sum, t, a[100];
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		for(i = sum = 0; i < n; i++) {
			scanf("%d", a + i);
			sum += a[i];
		}
		t = sum >> 1;
		memset(dp, 0, sizeof(i64)*(t+1));
		for(i = 0, dp[0] = 1; i < n; i++) {
			for(j = t; j >= a[i]; j--) {
				dp[j] |= dp[j-a[i]] << 1;
			}
		}
		o = (n+1) >> 1, e = n >> 1;
		for(j = t; j > 0; j--) {
			if(dp[j] & ((i64)1 << e)) break;
			if(dp[j] & ((i64)1 << o)) break;
		}
		printf("Case %d: %d %d\n", cs, j, sum - j);
	}
	return 0;
}