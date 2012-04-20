#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct { int x, y; } point;

point P[16];
int dp[1 << 16], n;

int coLinear(const point &a, const point &b, const point &c) {
	return a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y);
}

int solve(int mask, int curr, int cnt) {
	if(curr == -1) return 0;
	if(dp[mask] != -1) return dp[mask];
	int &ret = dp[mask]; ret = cnt;
	int i, j, next, nmask, tmp;
	for(i = 0; i < n; i++) {
		if((mask&(1<<i)) || i==curr) continue;
		nmask = mask | (1<<curr), next = -1, tmp = cnt-1;
		for(j = n-1; j >= 0; j--) {
			if((mask&(1<<j)) || j==curr) continue;
			if(coLinear(P[curr], P[i], P[j])) next = j;
			else nmask |= (1<<j), tmp--;
		}
		ret = min(ret, 1 + solve(nmask, next, tmp));
	}
	return ret;
}

int main() {
	int test, cs, i;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		for(i = 0; i < n; i++) scanf("%d %d", &P[i].x, &P[i].y);
		memset(dp, -1, sizeof dp);
		printf("Case %d: %d\n", cs, solve(0, 0, n));
	}
	return 0;
}
