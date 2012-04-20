#include <cmath>
#include <cstdio>
using namespace std;

void factor(long long n, int *cnt, int &len) {
	int rt, i;
	len = 0; if(n < 0) n = -n;
	if(!(n & 1)) {
		cnt[len] = 1, n >>= 1;
		while(!(n & 1)) {
			cnt[len]++;
			n >>= 1;
		}
		len++;
	}
	rt = (int)sqrt(n);
	for(i = 3; i <= rt; i+=2) {
		if(n % i == 0) {
			cnt[len] = 1, n /= i;
			while(n % i == 0) {
				cnt[len]++;
				n /= i;
			}
			len++, rt = (int)sqrt(n);
		}
	}
	if(n > 1) cnt[len++] = 1;
}

int gcd(int a, int b) {
	while(b) b^=a^=b^=a%=b;
	return a;
}

int main() {
	int n, cnt[10], len, test, cs = 1, i, a;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		factor(n, cnt, len);
		for(a = i = 0; i < len; i++) a = gcd(a, cnt[i]);
		if(n < 0) while(!(a & 1)) a >>= 1;
		printf("Case %d: %d\n", cs, a);
	}
	return 0;
}
