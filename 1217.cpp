#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;

int num[1024], dp[1024], n, flag;

int solve(int pos) {
	if(pos >= n) return 0;
	if(pos == n-1 && flag) return 0;
	if(dp[pos] != -1) return dp[pos];
	int &ret = dp[pos];
	ret = max(solve(pos + 1), num[pos] + solve(pos + 2));
	return ret;
}

int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	int test, cs = 1, i, r1, r2;
	scanf("%d", &test);
	while(test--) {
		scanf("%d", &n);
		for(i = 0; i < n; i++) {
			scanf("%d", &num[i]);
		}
		memset(dp, -1, sizeof (dp)); flag = 1; r1 = solve(2) + num[0];
		memset(dp, -1, sizeof (dp)); flag = 0; r2 = solve(1);
		printf("Case %d: %d\n", cs++, max(r1, r2));
	}
	return 0;
}
