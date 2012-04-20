#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const double EPS = 1e-9;

double dist3D(const int *A, const int *B) {
	int dsq, i;
	for(i = dsq = 0; i < 3; i++) dsq += (A[i]-B[i])*(A[i]-B[i]);
	return sqrt((double)dsq);
}

double triArea(const double &ab, const double &bc, const double &ca) {
	double s = (ab + bc + ca) / 2.0;
	return sqrt(s * (s-ab) * (s-bc) * (s-ca));
}

int main() {
	int test, cs, A[3], B[3], C[3];
	double ab, bc, ca, area, h, abl, abr;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d %d", A, A+1, A+2);
		scanf("%d %d %d", B, B+1, B+2);
		scanf("%d %d %d", C, C+1, C+2);
		ab = dist3D(A, B);
		bc = dist3D(B, C);
		ca = dist3D(C, A);
		area = triArea(ab, bc, ca);
		h = 2.0 * area / ab;
		abl = sqrt(ca*ca - h*h);
		abr = sqrt(bc*bc - h*h);
		if(abl + abr > ab + EPS) printf("Case %d: %.8lf\n", cs, min(ca, bc) + EPS);
		else printf("Case %d: %.8lf\n", cs, EPS + h);
	}
	return 0;
}
