#include <cstdio>

typedef long long i64;

const int MOD = 1000003;

i64 fact[1000001];

int extendedEuclid(int A, int B, int &X, int &Y) {
	int x, y, a, b, m, n, u, v, q, r;
	v = x = 0, u = y = 1;
	for(a = A, b = B; a; b = a, a = r, x = u, y = v, u = m, v = n) {
		q = b / a, r = b % a;
		m = x - (u * q), n = y - (v * q);
	}
	X = x, Y = y;
	return b;
}

int modularInverse(int a, int n) {
	int x, y, r;
	extendedEuclid(a, n, x, y);
	r = x % n;
	return r < 0? r + n : r;
}

int main() {
	int test, cs, i, n, r;
	fact[0] = fact[1] = 1;
	for(i = 2; i <= 1000000; i++) fact[i] = (fact[i-1] * i) % MOD;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &n, &r);
		printf("Case %d: %lld\n", cs, (fact[n] * modularInverse((int)fact[n-r], MOD) * modularInverse((int)fact[r], MOD)) % MOD);
	}
	return 0;
}