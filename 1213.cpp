#include <cstdio>
using namespace std;

int xp(int b, int n, int m) {
	int r = 1;
	while(n > 0) {
		if(n & 1) {
			r = r * b;
			if(r >= m) r %= m;
		}
		n >>= 1;
		b = b * b;
		if(b >= m) b %= m;
	}
	return r % m;
}

int main() {
	int s, m, b, n, k, test, i, cs = 1;
	scanf("%d", &test);
	while(test--) {
		scanf("%d %d %d", &n, &k, &m);
		for(s = i = 0; i < n; i++) {
			scanf("%d", &b);
			if(b >= m) b %= m;
			s += b;
			if(s >= m) s %= m;
		}
		s *= xp(n, k-1, m);
		if(s >= m) s %= m;
		if(k >= m) k %= m;
		printf("Case %d: %d\n", cs++, (s * k) % m);
	}
	return 0;
}
