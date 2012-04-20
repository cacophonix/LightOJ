#include <cstdio>
#include <cmath>

double save[1000001], deno[1001];

int main() {
	int test, cs, n, b;
	for(n = 1; n < 1000001; n++) save[n] = log10(n) + save[n-1];
	for(b = 2; b < 1001; b++) deno[b] = log10(b);
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &n, &b);
		printf("Case %d: %.0lf\n", cs, floor(save[n]/deno[b]) + 1.0);
	}
	return 0;
}
