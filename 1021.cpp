#include <cstdio>
#include <cstring>
using namespace std;

#define i64 long long
#define MAX 16
#define dig(p) ((p<65)?p-48:p-55)

int k, b, n;
char digits[MAX + 1];
i64 dp[1<<MAX][20];

i64 solve(int mod, int mask) {
	if(mask + 1 == (1 << n)) return (mod == 0);
	if(dp[mask][mod] != -1) return dp[mask][mod];
	i64 &ret = dp[mask][mod]; ret = 0;
	for(int i = 0; i < n; i++) {
		if(mask & (1<<i)) continue;
		ret += solve((mod * b + dig(digits[i])) % k, mask | (1 << i));
	}
	return ret;
}

int main() {
	int test, cs;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d %s", &b, &k, digits);
		n = strlen(digits);
		memset(dp, -1, sizeof(dp));
		printf("Case %d: %lld\n", cs, solve(0, 0));
	}
	return 0;
}
