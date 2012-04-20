#include <cstdio>

int main() {
	int k, i, j, test, cs, n, p, id;
	double Hn[1000001], val;
	Hn[0] = val = 0.0;
	for(i = k = 1; k <= 1000000; k++) {
		for(j = 0; j < 100; j++, i++) {
			val += (1.0 / (double)i);
		}
		Hn[k] = val;
	}
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		id = n / 100; p = n - 100*id; k = 100*id + 1;
		val = Hn[id];
		for(i = 0; i < p; i++, k++) {
			val += 1.0 / (double)k;
		}
		printf("Case %d: %.10lf\n", cs, val + (1e-12));
	}
	return 0;
}
