#include <cstdio>
#include <cmath>

#define MAX 10000000
#define LMT 3162
#define LEN 664579
#define i64 long long
#define ifc(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x) (flag[x>>6]|=(1<<((x>>1)&31)))

int flag[(MAX+64) >> 6], primes[LEN], len;
int cnt[16], faclen;

void sieve() {
	int i, j, k; primes[0] = 2; len = 1;
	for(i = 3; i < LMT; i+=2) if(!ifc(i))
		for(j = i*i, k = i<<1; j < MAX; j+=k) isc(j);
	for(i = 3; i < MAX; i+=2) if(!ifc(i)) primes[len++] = i;
}

void factor(i64 n) {
	int i, rt = sqrt((double)n);
	faclen = 0;
	for(i = 0; i < len && primes[i] <= rt; i++) {
		if(n % primes[i] == 0) {
			n /= primes[i];
			cnt[faclen] = 1;
			while(n % primes[i] == 0) {
				n /= primes[i];
				cnt[faclen]++;
			}
			faclen++;
			rt = sqrt((double)n);
		}
	}
	if(n > 1) cnt[faclen++] = 1;
}

int main() {
	int test, cs, i, j;
	i64 n, lt, rt, nways;
	sieve();
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%lld", &n);
		factor(n); nways = 0;
		for(i = 0; i < (1<<faclen); i++) {
			lt = rt = 1;
			for(j = 0; j < faclen; j++) {
				if(i & (1<<j)) lt *= cnt[j]+1;
				else rt *= cnt[j];
			}
			nways += lt * rt;
		}
		nways = (nways+1) >> 1;
		printf("Case %d: %lld\n", cs, nways);
	}
	return 0;
}
