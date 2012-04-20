#include <cstdio>
#include <cmath>

#define MAX 1000000
#define LMT 1000
#define i64 long long

int flag[1000064 >> 6], primes[78498], total;

#define ifc(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x) (flag[x>>6]|=(1<<((x>>1)&31)))

void sieve() {
	int i, j, k;
	primes[0] = 2; total = 1;
	for(i = 3; i < LMT; i += 2) if(!ifc(i)) for(j = i*i, k=i<<1; j < MAX; j += k) isc(j);
	for(i = 3; i < MAX; i += 2) if(!ifc(i)) primes[total++] = i;
}

int nod(i64 n) {
	int ret = 1, i, cnt, rt = (int)sqrt((double)n);
	for(i = 0; i < total && primes[i] <= rt; i++) {
		if(n % primes[i] == 0) {
			n /= primes[i], cnt = 1;
			while(n % primes[i] == 0) n/= primes[i], cnt++;
			ret *= (cnt + 1), rt = (int)sqrt((double)n);
		}
	}
	if(n > 1) ret <<= 1;
	return ret - 1;
}

int main() {
	int test, cs;
	i64 n;
	sieve();
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%lld", &n);
		printf("Case %d: %d\n", cs, nod(n));
	}
	return 0;
}

