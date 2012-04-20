#include <cstdio>
#include <algorithm>
using namespace std;

double dp[101];
double gold[101];

double solve(int pos, int n) {
	if(pos == n) return 0.0;
	if(dp[pos] > -1.0) return dp[pos];
	int next = min(6, n-pos-1), i;
	double ret = 0.0;
	if(next > 0) {
		for(i = 1; i <= next; i++) ret += solve(pos + i, n);
		ret /= (double)next;
	}
	return dp[pos] = gold[pos] + ret;
}

int main() {
	int test, cs, n, i;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		for(i = 0; i < n; i++) {
			scanf("%lf", gold + i);
			dp[i] = -1.0;
		}
		printf("Case %d: %.8lf\n", cs, solve(0, n));
	}
	return 0;
}
