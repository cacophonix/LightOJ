#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;

int dp[102][102][102]; unsigned char flag[102][102][102];
int n, test, cs, a[102] = {INT_MIN};

int solve(int pos, int lt, int rt) {
	if(pos > n) return 0;
	if(flag[pos][lt][rt] == cs) return dp[pos][lt][rt];
	flag[pos][lt][rt] = cs;
	int &ret = dp[pos][lt][rt];
	ret = solve(pos + 1, lt, rt);
	if(a[lt] <= a[pos] && a[pos] <= a[rt]) {
		ret = max(ret, solve(pos + 1, pos, rt) + 1);
		ret = max(ret, solve(pos + 1, lt, pos) + 1);
	}
	return ret;
}

int main() {
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", a + i);
		a[n+1] = INT_MAX;
		printf("Case %d: %d\n", cs, solve(1, 0, n+1));
	}
	return 0;
}
