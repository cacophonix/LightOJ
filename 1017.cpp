#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct { int x, y; } Point;

int dp[128][128];
Point points[128];
int n, w, k;

inline bool comp(const Point &a, const Point &b) {
	return (a.y == b.y) ? (a.x < b.x) : (a.y < b.y);
}

int solve(int i, int d) {
	if(i == n || d == k) return 0;
	int p, q, &ret = dp[i][d];
	if(ret != -1) return ret;
	for(p = i; p < n && points[p].y - points[i].y <= w; p++);
	for(q = i+1; q < n && points[q].y == points[i].y; q++);
	ret = max(solve(q, d), solve(p, d+1) + p - i);
	return ret;
}

int main() {
	int test, cs, i;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d %d", &n, &w, &k);
		for(i = 0; i < n; i++) scanf("%d %d", &points[i].x, &points[i].y);
		sort(points, points + n, comp);
		memset(dp, -1, sizeof dp);
		printf("Case %d: %d\n", cs, solve(0, 0));
	}
	return 0;
}
