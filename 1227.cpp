#include <stdio.h>
#include <string.h>

int main() {
	int test, cs = 1, n, p, q, a[32], i, tot, cnt[11];
	scanf("%d", &test);
	while(test--) {
		scanf("%d %d %d", &n, &p, &q);
		memset(cnt, 0, sizeof cnt);
		for(i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			cnt[a[i]]++;
		}
		for(i = 1, n = 0; i < 11; i++) while(cnt[i]--) a[n++] = i;
		n = p<n?p:n;
		for(i = tot = 0; i < n; i++) {
			tot += a[i];
			if(tot > q) break;
		}
		printf("Case %d: %d\n", cs++, i);
	}
	return 0;
}
