#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int test, cs, i, j, k, n, a[50], ans;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		for(i = 0; i < n; i++) scanf("%d", a + i);
		sort(a, a + n);
		for(i = ans = 0; i < n; i++) {
			for(j = i; j < n && a[j] == a[i]; j++);
			k = j - i;
			ans += ((k + a[i]) / (a[i] + 1)) * (a[i] + 1);
			i = j - 1;
		}
		printf("Case %d: %d\n", cs, ans);
	}
	return 0;
}