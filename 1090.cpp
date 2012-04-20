#include <cstdio>

int calcf5(int n) {
	int ret = 0;
	while(n > 0) {
		n /= 5;
		ret += n;
	}
	return ret;
}

int calcf2(int n) {
	int ret = 0;
	while(n > 0) {
		n >>= 1;
		ret += n;
	}
	return ret;
}

int calcn2(int n) {
	int ret = 0;
	while((n&1) == 0) {
		ret++;
		n >>= 1;
	}
	return ret;
}

int calcn5(int n) {
	int ret = 0;
	while(n % 5 == 0) {
		ret++;
		n /= 5;
	}
	return ret;
}

int main() {
	int test, cs, n, r, p, q, t5, t2;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d %d %d", &n, &r, &p, &q);
		t5 = calcf5(n) - calcf5(r) - calcf5(n - r) + q * calcn5(p);
		t2 = calcf2(n) - calcf2(r) - calcf2(n - r) + q * calcn2(p);
		printf("Case %d: %d\n", cs, t5 < t2 ? t5 : t2);
	}
	return 0;
}