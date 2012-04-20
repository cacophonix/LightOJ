#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	int test, cs = 1;
	double r1, r2, r3, h, p, pi = acos(-1.0), area;
	scanf("%d", &test);
	while(test--) {
		scanf("%lf %lf %lf %lf", &r1, &r2, &h, &p);
		r3 = (r1-r2) / h * (r2*h / (r1-r2) + p);
		area = pi*p*(r2 * r2 + r2* r3 + r3*r3)/3.0;
		printf("Case %d: %.10lf\n", cs++, area + 1e-9);
	}
	return 0;
}
