#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

bool flag[10000];
int primes[1230], len;
int fcnt[10000];
char buff[4096];
int reslen, mxf;

void sieve() {
	int i, j, k;
	primes[0] = 2; len = 1;
	for(i = 3; i < 10000; i+=2) {
		if(!flag[i]) {
			primes[len++] = i;
			if(i >= 100) continue;
			for(j=i*i, k=i<<1; j < 10000; j += k) flag[j] = true;
		}
	}
}

void factor(int a) {
	int i, cnt, rt = (int)sqrt(a);
	for(i = 0; i < len && primes[i] <= rt; i++) {
		if(a % primes[i] == 0) {
			a /= primes[i], cnt = 1;
			while(a % primes[i] == 0) {
				a /= primes[i];
				cnt++;
			}
			rt = (int)sqrt(a);
			if(fcnt[primes[i]] < cnt) fcnt[primes[i]] = cnt;
			if(primes[i] > mxf) mxf = primes[i];
		}
	}
	if(a > 1) {
		if(fcnt[a] < 1) fcnt[a] = 1;
		if(a > mxf) mxf = a;
	}
}

void mul(int a) {
	int i, k, carry, x;
	for(i = carry = k = 0; i < reslen || carry; i++, k++) {
		x = ((i < reslen)? buff[i]-48 : 0) * a + carry;
		buff[k] = x % 10 + 48;
		carry = x / 10;
	}
	buff[k] = 0, reslen = k;
}

int main() {
	int i, j, test, cs, n, a, f;
	sieve();
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		memset(fcnt, 0, sizeof fcnt);
		buff[0] = '1'; buff[1] = 0; reslen = 1; mxf = 0;
		for(i = 0; i < n; i++) {
			scanf("%d", &a);
			factor(a);
		}
		for(i = 0; i < len && primes[i] <= mxf; i++) {
			for(f = 1, j = 0; j < fcnt[primes[i]]; j++) f *= primes[i];
			if(f > 1) mul(f);
		}
		reverse(buff, buff+reslen);
		printf("Case %d: %s\n", cs, buff);
	}
	return 0;
}
