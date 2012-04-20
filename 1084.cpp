#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f, MAX = 100000;

int a[MAX], n, k;
int dp[MAX], vis[MAX], flagv;

int solve(int pos) {
	if(pos >= n) return 0;
	if(vis[pos] == flagv) return dp[pos];
	vis[pos] = flagv;
	int v = a[pos] + (k << 1);
	int npos = upper_bound(a, a + n, v) - a;
	int &ret = dp[pos]; ret = INF;
	if(npos - pos >= 3) ret = min(ret, 1 + solve(npos));
	if(npos - pos >= 4) ret = min(ret, 1 + solve(npos - 1));
	if(npos - pos >= 5) ret = min(ret, 1 + solve(npos - 2));
	return ret;
}

int main() {
	int test, cs, i;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		flagv = cs;
		scanf("%d %d", &n, &k);
		for(i = 0; i < n; i++) scanf("%d", a + i);
		sort(a, a + n);
		i = solve(0);
		if(i == INF) printf("Case %d: -1\n", cs);
		else printf("Case %d: %d\n", cs, i);
	}
	return 0;
}