#include <cstdio>
using namespace std;

const int MAX = 1024;

int a[MAX];

bool possible(int n, int m, int c) {
	int i, sum = 0, k = 1;
	for(i = 0; i < n; i++) {
		sum += a[i];
		if(sum > c) {
			sum = a[i];
			k++;
		}
	}
	return k <= m;
}

int main() {
	int test, cs, n, m, i, lo, hi, md;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &n, &m);
		lo = hi = 0;
		for(i = 0; i < n; i++) {
			scanf("%d", a + i);
			if(a[i] > lo) lo = a[i];
			hi += a[i];
		}
		while(lo < hi) {
			md = (lo + hi) >> 1;
			if(possible(n, m, md)) hi = md;
			else lo = md + 1;
		}
		printf("Case %d: %d\n", cs, hi);
	}
	return 0;
}