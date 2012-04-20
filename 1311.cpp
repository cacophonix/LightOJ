#include <cstdio>
#include <algorithm>

int main() {
	double u1, u2, u3, a1, a2, s, t1, t2, t, eps = 1e-10;
	int test, cs;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%lf %lf %lf %lf %lf", &u1, &u2, &u3, &a1, &a2);
		t1 = u1 / a1;
		t2 = u2 / a2;
		t = std::max(t1, t2);
		s = u1 * u1 / (2.0 * a1) + u2 * u2 / (2.0 * a2);
		printf("Case %d: %.8lf %.8lf\n", cs, s + eps, t * u3 + eps);
	}
	return 0;
}
