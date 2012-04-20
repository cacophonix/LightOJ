#include <cstdio>
#include <algorithm>
using namespace std;

int points[100001];

int main() {
	int test, cs, n, i, a, b, q;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &n, &q);
		for(i = 0; i < n; i++) scanf("%d", points + i);
		printf("Case %d:\n", cs);
		while(q--) {
			scanf("%d %d", &a, &b);
			a = lower_bound(points, points + n, a) - points;
			b = upper_bound(points + a, points + n, b) - points;
			printf("%d\n", b - a);
		}
	}
	return 0;
}
