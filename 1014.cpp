#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int test, cs, p, l, n, sz, rt;
	vector< int > V;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &p, &l); n = p - l; rt = (int)sqrt(n);
		V.clear();
		for(p = 1; p <= rt; p++) {
			if(n % p == 0) {
				if(p > l) V.push_back(p);
				if(p * p != n) {
					if(n / p > l) V.push_back(n / p);
				}
			}
		}
		if(V.empty()) printf("Case %d: impossible\n", cs);
		else {
			sort(V.begin(), V.end()); sz = V.size();
			printf("Case %d:", cs);
			for(p = 0; p < sz; p++) printf(" %d", V[p]);
			printf("\n");
		}
	}
	return 0;
}
