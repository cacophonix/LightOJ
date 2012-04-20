#include <cstdio>

int main() {
	int n, m, k, test, cs, i, j, p, q;
	int flag[32][32], sol[32], sat[32];
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d %d", &n, &m, &p);
		for(i = 0; i < n; i++)
			for(j = 0; j < p; j++)
				scanf("%d", &flag[i][j]);
		scanf("%d", &q);
		for(i = 0; i < q; i++) scanf("%d", sol + i);
		for(i = 0; i < n; i++) {
			for(j = 0; j < p; j++) {
				if(flag[i][j] < 0) {
					for(k = 0; k < q; k++) if(sol[k] == -flag[i][j]) break;
					if(k == q) break;
				}
				else {
					for(k = 0; k < q; k++) if(sol[k] == flag[i][j]) break;
					if(k < q) break;
				}
			}
			if(j == p) break;
		}
		if(i == n) printf("Case %d: Yes\n", cs);
		else printf("Case %d: No\n", cs);
	}
	return 0;
}
