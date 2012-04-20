#include <cstdio>

#define min(a, b) ((a<b)?a:b)

int main() {
	int test, cs, color[20][3], n, i, j, ans;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		for(i = 0; i < n; i++)
			for(j = 0; j < 3; j++)
				scanf("%d", &color[i][j]);
		for(i = 1; i < n; i++) {
			for(j = 0; j < 3; j++) {
				switch(j) {
					case 0: color[i][j] += min(color[i-1][1], color[i-1][2]); break;
					case 1: color[i][j] += min(color[i-1][0], color[i-1][2]); break;
					case 2: color[i][j] += min(color[i-1][0], color[i-1][1]); break;
				}
			}
		}
		ans = min(color[n-1][0], min(color[n-1][1], color[n-1][2]));
		printf("Case %d: %d\n", cs, ans);
	}
	return 0;
}
