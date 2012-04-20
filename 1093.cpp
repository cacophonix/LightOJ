#include <cstdio>

#define MAX 100009
#define max(a, b) ((a)>(b)?(a):(b))

int maxDeq[MAX][2], maxTop, maxBot;
int minDeq[MAX][2], minTop, minBot;

int main() {
	int test, cs, n, d, i, v, maxdiff;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &n, &d);
		maxTop = minTop = maxBot = minBot = maxdiff = 0;
		for(i = 0; i < n; i++) {
			scanf("%d", &v);
			while(maxBot < maxTop && maxDeq[maxTop-1][0] < v) maxTop--;
			maxDeq[maxTop][0] = v; maxDeq[maxTop][1] = i; maxTop++;
			while(minBot < minTop && minDeq[minTop-1][0] > v) minTop--;
			minDeq[minTop][0] = v; minDeq[minTop][1] = i; minTop++;
			while(maxBot < maxTop && i-maxDeq[maxBot][1] >= d) maxBot++;
			while(minBot < minTop && i-minDeq[minBot][1] >= d) minBot++;
			maxdiff = max(maxdiff, maxDeq[maxBot][0] - minDeq[minBot][0]);
		}
		printf("Case %d: %d\n", cs, maxdiff);
	}
	return 0;
}
