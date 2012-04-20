#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool vis[1001][1001];
double dp[1001][1001];

double solve(int t,int d) {
	if(!t) return 1.0;
	if(vis[t][d]) return dp[t][d];
	vis[t][d] = 1;
	double &r = dp[t][d]; r = 0.0;
	double p = 0.0, n = t + d + 1, dk = 0.0;
	if(t >= 2) r += (t*(t-1) / (n*(n-1))) * solve(t-2, d);
	if(d >= 1) {
		r += 2.0*t*d / (n*(n-1)) * solve(t,d-1);
		dk = 2.0*d / (n*(n-1)) * solve(t,d-1);
	}
	if(d >= 2) p = d*(d-1) / (n*(n-1));
	r = max( (r+dk)/(1-p),r/(1-p-(2.0*d/(n*(n-1)))) );
	return r;
}

int main() {
	int test, cs, t, d;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &t, &d);
		printf("Case %d: %.8lf\n", cs, solve(t, d) + 1e-10);
	}
	return 0;
}
