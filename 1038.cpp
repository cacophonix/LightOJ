#include <cstdio>
#include <cmath>

double dp[100001];
int vis[100001];

double solve(int n) {
	if(n == 1) return 0.0;
	if(vis[n]) return dp[n];
	vis[n] = 1;
	double &ret = dp[n]; ret = 0.0;
	int i, tot = 0, rs = (int)sqrt((double)n);
	for(i = 1; i <= rs; i++) {
		if(n % i) continue;
		if(i * i != n) {
			tot += 2;
			ret += 2.0 + solve(n / i) + solve(i);
		}
		else {
			tot++;
			ret += 1.0 + solve(i);
		}
	}
	return ret = ret / (double)(tot - 1);
}

int main() {
	int test, cs, n;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		printf("Case %d: %.8lf\n", cs, solve(n) + 1e-9);
	}
	return 0;
}
