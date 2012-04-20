#include <cstdio>
#include <cstring>

int dp[10][82][82][2], len, k;
int vis[10][82][82][2], flagv;
char num[16];

int solve(int pos, int nmod, int smod, int pref) {
	if(pos == len) return (!nmod && !smod);
	int &ret = dp[pos][nmod][smod][pref];
	if(vis[pos][nmod][smod][pref] == flagv) return ret;
	vis[pos][nmod][smod][pref] = flagv; ret = 0;
	int i, d = num[pos] - 48, num, sum, pre;
	for(i = 0; i < 10; i++) {
		if(pref && i > d) break;
		num = (nmod * 10 + i) % k;
		sum = (smod + i) % k;
		pre = (i < d)? 0 : pref;
		ret += solve(pos + 1, num, sum, pre);
	}
	return ret;
}

int calc(int a) {
	sprintf(num, "%d", a);
	len = strlen(num);
	return solve(0, 0, 0, 1);
}

int main() {
	int test, cs, a, b, cb, ca;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d %d", &a, &b, &k);
		if(k == 1) {
			printf("Case %d: %d\n", cs, b - a + 1);
			continue;
		}
		if(k > 82) {
			printf("Case %d: 0\n", cs);
			continue;
		}
		flagv = cs << 1;
		ca = calc(a-1);
		flagv++;
		cb = calc(b);
		printf("Case %d: %d\n", cs, cb - ca);
	}
	return 0;
}