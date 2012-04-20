#include <cstdio>

typedef long long i64;

int main() {
	int i, cs, test, buff[21], len;
	i64 fact[21] = {1}, n;
	for(i = 1; i < 21; i++) fact[i] = fact[i-1] * i;
	scanf("%d", &cs);
	for(test = 1; test <= cs; test++) {
		scanf("%lld", &n);
		for(i = 20, len = 0; i >= 0 && n > 0; i--) {
			if(fact[i] > n) continue;
			buff[len++] = i, n -= fact[i];
		}
		if(n != 0) printf("Case %d: impossible\n", test);
		else {
			printf("Case %d: ", test);
			while(len--) printf("%d!%c", buff[len], (len?'+':'\n'));
		}
	}
	return 0;
}
