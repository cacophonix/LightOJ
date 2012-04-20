#include <cstdio>
#include <cmath>

const double EPS = 1e-9;

int main() {
	int test, cs;
	double a, b, c, sab, sbc, sca, s, tarea, area;
	double alp, bet, gam;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%lf %lf %lf", &a, &b, &c);
		sab = a + b; sbc = b + c; sca = c + a;
		s = (sab + sbc + sca) * 0.5;
		tarea = sqrt(s * (s - sab) * (s - sbc) * (s - sca));
		alp = acos((sab * sab + sca * sca - sbc * sbc) / (2.0 * sab * sca));
		bet = acos((sab * sab + sbc * sbc - sca * sca) / (2.0 * sab * sbc));
		gam = acos((sbc * sbc + sca * sca - sab * sab) / (2.0 * sbc * sca));
		area = tarea - 0.5 * alp * a * a - 0.5 * bet * b * b - 0.5 * gam * c * c;
		printf("Case %d: %.8lf\n", cs, area + EPS);
	}
	return 0;
}
