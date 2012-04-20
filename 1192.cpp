#include <cstdio>
using namespace std;

int main() {
	int test, cs, n, i, a, b, xsum;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		for(xsum = i = 0; i < n; i++) {
			scanf("%d %d", &a, &b);
			xsum ^= (b - a - 1);
		}
		if(xsum) printf("Case %d: Alice\n", cs);
		else printf("Case %d: Bob\n", cs);
	}
	return 0;
}
