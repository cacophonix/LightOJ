#include <cstdio>

int gcd(int a, int b) {
	while(b) b ^= a ^= b ^= a %= b;
	return a;
}

int main() {
	int test, cs, n, i, v, sum, cnt, g;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		for(cnt = i = sum = 0; i < n; i++) {
			scanf("%d", &v);
			if(v < 0) {
				v = -v;
				cnt++;
			}
			sum += v;
		}
		if(cnt == n) printf("Case %d: inf\n", cs);
		else {
			g = gcd(sum, n - cnt);
			printf("Case %d: %d/%d\n", cs, sum/g, (n-cnt)/g);
		}
	}
	return 0;
}
