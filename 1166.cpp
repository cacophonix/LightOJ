#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int test, cs, n, i, ans, a[128], b[128];
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		for(i = 1; i <= n; i++) {
			scanf("%d", a + i);
			b[a[i]] = i;
		}
		for(i = 1, ans = 0; i <= n; i++) {
			if(a[i] != i) {
				ans++;
				b[a[i]] = b[i];
				swap(a[b[i]], a[i]);
				b[i] = i;
			}
		}
		printf("Case %d: %d\n", cs, ans);
	}
	return 0;
}