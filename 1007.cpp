#include <stdio.h>

#define MAX 5000000
#define i64 unsigned long long
#define nextint(ret) ret=0;while(*ptr<48)ptr++;do{ret=ret*10+*ptr++-48;}while(*ptr>47);

int etf[MAX + 1];
i64 sum[MAX + 1];

static char buff[1600000], *ptr = buff;

inline void phi() {
	register int i, j;
	for(etf[2] = 1, j = 4; j <= MAX; j+=2) etf[j] = j >> 1;
	for(i = 3; i <= MAX; i+=2) if(!etf[i]) {
		for(etf[i] = i-1, j = i<<1; j <= MAX; j+=i) {
			if(!etf[j]) etf[j] = j;
			etf[j] = etf[j] / i * (i-1);
		}
	}
	for(i = 2; i <= MAX; i++) sum[i] = sum[i-1] + (i64)etf[i]*etf[i];
}

int main() {
	int test, cs = 1, a, b;
	phi();
	fread(buff, 1, 1600000, stdin);
	nextint(test);
	while(test--) {
		nextint(a); nextint(b);
		printf("Case %d: %llu\n", cs++, sum[b] - sum[a-1]);
	}
	return 0;
}
