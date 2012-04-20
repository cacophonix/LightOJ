#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 50;

int a[MAX], b[MAX];
char f1[MAX], f2[MAX];

int main() {
	int test, cs, i, j, ans, n, last;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		for(i = 0; i < n; i++) scanf("%d", a + i);
		for(i = 0; i < n; i++) scanf("%d", b + i);
		sort(a, a + n);
		sort(b, b + n);
		memset(f1, 0, sizeof f1);
		memset(f2, 0, sizeof f2);
		for(ans = i = 0; i < n; i++) {
			for(last = -1, j = 0; j < n; j++) {
				if(a[i] < b[j]) break;
				if(f2[j]) continue;
				if(a[i] > b[j]) last = j;
			}
			if(last != -1) {
				ans += 2;
				f1[i] = f2[last] = 1;
			}
		}
		for(i = 0; i < n; i++) {
			if(f1[i]) continue;
			for(j = 0; j < n; j++) {
				if(a[i] < b[j]) break;
				if(f2[j]) continue;
				if(a[i] == b[j]) {
					f2[j] = 1;
					ans++;
					break;
				}
			}
		}
		printf("Case %d: %d\n", cs, ans);
	}
	return 0;
}