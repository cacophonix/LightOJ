#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
	while(b) b ^= a ^= b ^= a %= b;
	return a;
}

int main() {
	int test, cs, i, j, k, n, x1, y1, g, r, ans, x[700], y[700];
	pair< int, int > slope[700], tmp;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		for(i = 0; i < n; i++) {
			scanf("%d %d", &x[i], &y[i]);
		}
		if(n < 3) {
			printf("Case %d: %d\n", cs, n);
			continue;
		}
		for(i = ans = 0; i < n; i++) {
			for(j = i + 1, k = 0; j < n; j++) {
				y1 = y[i] - y[j];
				x1 = x[i] - x[j];
				g = gcd(abs(y1), abs(x1));
				if(g) y1 /= g, x1 /= g;
				if(x1 < 0) y1 *= -1, x1 *= -1;
				if(x1 == 0 && y1 < 0) y1 = -y1;
				slope[k++] = make_pair(y1, x1);
			}
			sort(slope, slope + k);
			for(j = 0; j < k; j++) {
				tmp = slope[j];
				for(g = j, r = 0; g < k; g++) {
					if(slope[g] != tmp) break;
					r++;
				}
				j = g - 1;
				if(ans < r + 1) ans = r + 1;
			}
		}
		printf("Case %d: %d\n", cs, ans);
	}
	return 0;
}
