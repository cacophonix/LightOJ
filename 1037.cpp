#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char mat[16][16];
int dp[1<<15], hp[16], n;

int solve(int mask) {
	if(mask == (1<<n)-1) return 0;
	if(dp[mask] != -1) return dp[mask];
	int &ret = dp[mask], i, j, k;
	for(i = 0, ret = 0x7f7f7f7f; i < n; i++) {
		if(!(mask & (1 << i))) {
			ret = min(ret, hp[i] + solve(mask | (1 << i)));
			for(j = 0; j < n; j++) {
				if((mask & (1 << j)) && (k = mat[j][i]-'0')) {
					ret = min(ret, (hp[i]+k-1) / k + solve(mask | (1 << i)));
				}
			}
		}
	}
	return ret;
}

int main() {
	int test, cs, i;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		for(i = 0; i < n; i++) scanf("%d", hp + i);
		for(i = 0; i < n; i++) scanf("%s", mat[i]);
		memset(dp, -1, sizeof dp);
		printf("Case %d: %d\n", cs, solve(0));
	}
	return 0;
}
