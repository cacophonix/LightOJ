#include <cstdio>

#define MAX 100000
#define LMT 316
#define LEN 9592
#define MOD 10000019

int flag[MAX >> 6], primes[LEN], factors[LEN], nprime;

#define ifc(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x) (flag[x>>6]|=(1<<((x>>1)&31)))

void sieve() {
	int i, j, k;
	primes[nprime++] = 2;
	for(i = 3; i < LMT; i += 2) if(!ifc(i)) for(j = i * i, k = i << 1; j < MAX; j += k) isc(j);
	for(i = 3; i < MAX; i += 2) if(!ifc(i)) primes[nprime++] = i;
}

void factorize(int n) {
	int i, x;
	for(i = 0; i < nprime && primes[i] <= n; i++) {
		factors[i] = 0;
		x = n;
		while(x > 0) {
			factors[i] += x / primes[i];
			x /= primes[i];
		}
	}
}

long long modexp(int n, int p) {
	long long r = 1, b = n;
	while(p > 0) {
		if(p & 1) { r = r * b; if(r >= MOD) r %= MOD; }
		p >>= 1;
		b = b * b; if(b >= MOD) b %= MOD;
	}
	return r;
}

int main() {
	int test, cs, n, t, np, i;
	long long res;
	sieve();
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &n, &t);
		factorize(n);
		for(i = 0, res = 1, np = 1; i < nprime && primes[i] <= n; i++) {
			if(factors[i] >= t) {
				res = res * modexp(primes[i], factors[i] / t);
				if(res >= MOD) res %= MOD;
				np = 0;
			}
		}
		if(np) res = -1;
		printf("Case %d: %lld\n", cs, res);
	}
	return 0;
}