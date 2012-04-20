#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int test, cs, n, m, i, a[128], v;
	char opt[2];
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &n, &m);
		for(i = 0; i < n; i++) scanf("%d", &a[i]);
		while(m--) {
			scanf("%s", opt);
			switch(opt[0]) {
				case 'S':
					scanf("%d", &v);
					for(i = 0; i < n; i++) a[i] += v;
					break;
				case 'M':
					scanf("%d", &v);
					for(i = 0; i < n; i++) a[i] *= v;
					break;
				case 'D':
					scanf("%d", &v);
					for(i = 0; i < n; i++) a[i] /= v;
					break;
				case 'R':
					reverse(a, a + n);
					break;
				case 'P':
					scanf("%d %d", &i, &v);
					swap(a[i], a[v]);
			}
		}
		printf("Case %d:\n%d", cs, a[0]);
		for(i = 1; i < n; i++) printf(" %d", a[i]); printf("\n");
	}
	return 0;
}
