#include <cstdio>
#include <cmath>

typedef long long i64;

i64 calc(int n) {
	int i, j, rt = (int)sqrt((double)n);
	i64 sum = 0;
	for(i = 2; i <= rt; i++) {
		j = n / i;
		sum += (i64)i*(j-i+1) + (i64)j*(j+1)/2 - (i64)i*(i+1)/2;
	}
	return sum;
}

int main() {
	int test, cs, n;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		printf("Case %d: %lld\n", cs, calc(n));
	}
	return 0;
}