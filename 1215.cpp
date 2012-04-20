#include <cstdio>
#include <cmath>
using namespace std;

#define i64 long long

void factor(int n, int fac[], int cnt[], int &nfac) {
	int rt, i;
	if((n&1)==0) {
		n >>= 1; nfac = 1; fac[0] = 2; cnt[0] = 1;
		while((n&1)==0) { cnt[0]++; n >>= 1; }
	}
	else nfac = 0;
	rt = (int)sqrt(n);
	for(i = 3; i <= rt; i+=2) {
		if(n % i == 0) {
			n /= i; fac[nfac] = i; cnt[nfac] = 1;
			while(n % i == 0) { n /= i; cnt[nfac]++; }
			rt = (int)sqrt(n); nfac++;
		}
	}
	if(n > 1) { fac[nfac] = n; cnt[nfac] = 1; nfac++; }
}

int main() {
	int test, i, j, cs = 1, a, b, cnt[44], fac[44], nfac;
	i64 n, c;
	scanf("%d", &test);
	while(test--) {
		scanf("%d %d %lld", &a, &b, &n);
		if(n % a == 0 && n % b == 0) {
			factor(a, fac, cnt, nfac);
			for(i = 0; i < nfac; i++) {
				for(c = fac[i], j = 0; j < cnt[i]; j++, c *= fac[i]);
				if(n % c) {
					c /= fac[i];
					if(n % c == 0) n /= c;
				}
			}
			factor(b, fac, cnt, nfac);
			for(i = 0; i < nfac; i++) {
				for(c = fac[i], j = 0; j < cnt[i]; j++, c *= fac[i]);
				if(n % c) {
					c /= fac[i];
					if(n % c == 0) n /= c;
				}
			}
			printf("Case %d: %lld\n", cs++, n);
		}
		else printf("Case %d: impossible\n", cs++);
	}
	return 0;
}
