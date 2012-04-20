#include <cstdio>
#include <cstring>

int coin[101], cnt[101], MM[100001], CC[100001];

int main() {
	int test, cs, n, m, i, j, ans, cv, ct;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &n, &m);
		for(i = 0; i < n; i++) scanf("%d", &coin[i]);
		for(i = 0; i < n; i++) scanf("%d", &cnt[i]);
		
		memset(MM, 0, sizeof MM);
		for(i = 0, MM[0] = 1; i < n; i++) {
			cv = coin[i], ct = cnt[i];
			memset(CC, 0, sizeof CC);
			for(j = cv; j <= m; j++) {
				if(!MM[j] && CC[j-cv] < ct) {
					CC[j] = CC[j-cv] + 1;
					MM[j] |= MM[j-cv];
				}
			}
		}
		for(i = 1, ans = 0; i <= m; i++) ans += MM[i];
		printf("Case %d: %d\n", cs, ans);
	}
	return 0;
}
