#include <cstdio>

int main() {
	int test, cs, d, i;
	double prob;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &d);
		prob = 1.0;
		for(i = 1; prob > 0.5; i++) {
			prob *= (double)(d-i) / d;
		}
		printf("Case %d: %d\n", cs, i - 1);
	}
	return 0;
}
