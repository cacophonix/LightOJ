#include <cstdio>
#include <cmath>

typedef long long i64;

const int MOD = 1000000007;
const int MAX = 46656;
const int LMT = 216;

int flag[MAX >> 6], primes[4821], prlen;

#define ifc(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x) (flag[x>>6]|=(1<<((x>>1)&31)))

void sieve() {
	int i, j, k;
	for(i = 3; i < LMT; i+=2) if(!ifc(i))
		for(j = i*i, k=i<<1; j < MAX; j+=k) isc(j);
	prlen = 1; primes[0] = 2;
	for(i = 3; i < MAX; i+=2) if(!ifc(i)) primes[prlen++] = i;
}

void factorize(int n, int *factor, int *cnt, int &k) {
	int rt = (int)sqrt((double)n), i;
	for(i = k = 0; i < prlen && primes[i] <= rt; i++) {
		if(n % primes[i] == 0) {
			factor[k] = primes[i];
			cnt[k] = 1;
			n /= primes[i];
			while(n % primes[i] == 0) {
				n /= primes[i];
				cnt[k]++;
			}
			k++;
			rt = (int)sqrt((double)n);
		}
	}
	if(n > 1) {
		factor[k] = n;
		cnt[k] = 1;
		k++;
	}
}

int euclid(int A, int B, int &X, int &Y) {
	int a, b, q, r, x, y, m, n, u, v;
	x = 0, y = 1, u = 1, v = 0;
	for(a = A, b = B; a; b = a, a = r, x = u, y = v, u = m, v = n) {
		q = b / a, r = b % a, m = x - (u * q), n = y - (v * q);
	}
	X = x, Y = y;
	return b;
}

int modinv(int a, int n) {
	int x, y, d, r;
	d = euclid(a, n, x, y);
	r = x % n;
	return r < 0 ? r + n : r;
}

i64 modexp(i64 b, i64 p, int m) {
	i64 r = 1;
	while(p > 0) {
		if(p & 1) r = (r * b) % m;
		p >>= 1, b = (b * b) % m;
	}
	return r;
}

int main() {
	int test, cs, m, n, i, k, factor[32], cnt[32];
	i64 res, top, bot;
	sieve();
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &n, &m);
		factorize(n, factor, cnt, k);
		for(res = 1, i = 0; i < k; i++) {
			top = (modexp(factor[i], (i64)m * cnt[i] + 1, MOD) + MOD - 1) % MOD;
			bot = modinv(factor[i] - 1, MOD);
			res = (res * ((top * bot) % MOD)) % MOD;
		}
		printf("Case %d: %lld\n", cs, res);
	}
	return 0;
}