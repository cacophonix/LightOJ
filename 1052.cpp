#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long i64;

const int MOD = 1000000007;

i64 base[2][2] = {{1, 1}, {1, 0}}, unit[2][2] = {{1, 0}, {0, 1}};

inline void mul(i64 a[2][2], i64 b[2][2]) {
	i64 r[2][2];
	r[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % MOD;
	r[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % MOD;
	r[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % MOD;
	r[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % MOD;
	memcpy(a, r, sizeof r);
}

inline void pwr(i64 r[2][2], int p) {
	i64 b[2][2];
	memcpy(b, base, sizeof base);
	memcpy(r, unit, sizeof unit);
	while(p > 0) {
		if(p & 1) mul(r, b);
		p >>= 1;
		mul(b, b);
	}
}

int main() {
	int test, cs, n, x, m, y, k, i;
	i64 d, df1, df0, f[2], r[2][2], fib[46];
	fib[0] = 0, fib[1] = 1;
	for(i = 2; i < 46; i++) fib[i] = fib[i-1] + fib[i-2];
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d %d %d %d", &n, &x, &m, &y, &k);
		if(n > m) {
			swap(n, m);
			swap(x, y);
		}
		if(m >= 46) {
			printf("Case %d: Impossible\n", cs);
			continue;
		}
		d = fib[n] * fib[m-1] - fib[m] * fib[n-1];
		df1 = x * fib[m-1] - fib[n-1] * y;
		df0 = fib[n] * y - x * fib[m];
		if(df1 % d || df0 % d) {
			printf("Case %d: Impossible\n", cs);
			continue;
		}
		f[0] = df0 / d, f[1] = df1 / d;
		if(f[0] < 0 || f[1] < 0 || f[1] < f[0]) {
			printf("Case %d: Impossible\n", cs);
			continue;
		}
		pwr(r, k - 1);
		d = (r[0][0] * f[1] + r[0][1] * f[0]) % MOD;
		printf("Case %d: %lld\n", cs, d);
	}
	return 0;
}
