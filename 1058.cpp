#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct { int x, y; } Point;

Point p[1 << 10], m[1 << 19];

inline bool comp(const Point &a, const Point &b) {
	return (a.x == b.x) ? a.y < b.y : a.x < b.x;
}

int main() {
	int test, cs, n, i, j, k, ans;
	freopen("in.txt", "r", stdin);
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		for(i = 0; i < n; i++) scanf("%d %d", &p[i].x, &p[i].y);
		for(i = k = 0; i < n; i++) {
			for(j = i + 1; j < n; j++) {
				m[k].x = (p[i].x + p[j].x);
				m[k].y = (p[i].y + p[j].y);
				k++;
			}
		}
		sort(m, m + k, comp);
		for(ans = i = 0; i < k; i++) {
			for(j = i; j < k; j++) {
				if(m[i].x != m[j].x || m[i].y != m[j].y) break;
			}
			n = j - i; i = j - 1;
			ans += (n * (n-1)) >> 1;
		}
		printf("Case %d: %d\n", cs, ans);
	}
	return 0;
}