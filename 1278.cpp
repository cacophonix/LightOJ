#include <cstdio>
#include <cmath>

#define MAX 10010896
#define LMT 3164
#define i64 long long

int flag[MAX >> 6], primes[800000], total;

#define ifc(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x) (flag[x>>6]|=(1<<((x>>1)&31)))

void sieve() {
	int i, j, k;
	for(i = 3; i < LMT; i+=2) if(!ifc(i)) for(j=i*i, k=i<<1; j < MAX; j+=k) isc(j);
	primes[0] = 2, total = 1;
	for(i = 3; i < MAX; i+=2) if(!ifc(i)) primes[total++] = i;
}

int ndiv(i64 n) {
	int rt, i, cnt, ret;
	while(n > 0 && (n & 1)==0) n >>= 1;
	rt = (int)sqrt((double)n);
	for(i = ret = 1; primes[i] <= rt; i++) {
		if(n % primes[i] == 0) {
			n /= primes[i], cnt = 1;
			while(n % primes[i] == 0) {
				n /= primes[i];
				cnt++;
			}
			ret *= (cnt + 1);
			rt = (int)sqrt((double)n);
		}
	}
	if(n > 1) ret <<= 1;
	return ret;
}

int main() {
	int test, cs;
	i64 n;
	sieve();
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%lld", &n);
		printf("Case %d: %d\n", cs, ndiv(n)-1);
	}
	return 0;
}
