#include <cstdio>
#include <algorithm>
using namespace std;

int Y[50000];

int main() {
	int test, cs, n, w, x, y, i, j;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &n, &w);
		for(i = 0; i < n; i++) {
			scanf("%d %d", &x, &y);
			Y[i] = y;
		}
		sort(Y, Y + n);
		for(x = i = 0; i < n; i++) {
			y = Y[i], x++;
			for(j = i+1; j < n && Y[j]-y <= w; j++);
			i = j-1;
		}
		printf("Case %d: %d\n", cs, x);
	}
	return 0;
}
