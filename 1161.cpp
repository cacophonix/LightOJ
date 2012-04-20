#include <cstdio>
#include <cstring>

const int MAX = 10000;
typedef long long i64;

i64 ncr[MAX + 1], ans[MAX + 1];
int cnt[MAX + 1];

int main() {
	int i, test, cs, maxval, a, j, n;
	ncr[4] = 1;
	for(i = 5; i <= MAX; i++) ncr[i] = ncr[i-1]*i/(i-4);
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		memset(cnt, 0, sizeof cnt);
		for(maxval = i = 0; i < n; i++) {
			scanf("%d", &a);
			maxval = a > maxval ? a : maxval;
			for(j = 1; j*j <= a; j++) {
				if(a % j == 0) {
					cnt[j]++;
					if(j*j != a) cnt[a / j]++;
				}
			}
		}
		for(i = maxval; i; i--) {
			ans[i] = ncr[cnt[i]];
			for(j = i+i; j <= maxval; j += i) ans[i] -= ans[j];
		}
		printf("Case %d: %lld\n", cs, ans[1]);
	}
	return 0;
}
