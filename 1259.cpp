#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX 10010896
#define LMT 3164

int flag[MAX >> 6], primes[665254], total;

#define ifc(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x) (flag[x>>6]|=(1<<((x>>1)&31)))
#define isp(x) ((x==2)||((x>1)&&(x&1)&&(!ifc(x))))

void sieve() {
	int i, j, k; primes[0] = 2; total = 1;
	for(i = 3; i < LMT; i+=2) if(!ifc(i)) for(j = i*i, k = i << 1; j < MAX; j += k) isc(j);
	for(i = 3; i < MAX; i+=2) if(!ifc(i)) primes[total++] = i;
}

int main() {
	int test, cs, n, i, k, cnt;
	sieve();
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n); cnt = 0;
		i = upper_bound(primes, primes + total, n>>1) - primes;
		while(i--) {
			k = n - primes[i];
			if(isp(k)) cnt++;
		}
		printf("Case %d: %d\n", cs, cnt);
	}
	return 0;
}
