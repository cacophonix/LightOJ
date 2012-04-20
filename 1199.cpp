#include <cstdio>

const int MAX = 10001;

int g[MAX], tmp[MAX], flag[MAX];

void grundy() {
	int i, j, k;
	g[0] = g[1] = g[2] = 0;
	for(k = 3; k < MAX; k++) {
		for(i = 1, j = k-1; i < j; i++, j--) flag[g[i] ^ g[j]] = k;
		for(i = j = 0; i <= k && flag[j]==k; i++, j++);
		g[k] = j;
	}
}

int main() {
	int test, cs, i, n, ret, v;
	grundy();
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		for(i = ret = 0; i < n; i++) {
			scanf("%d", &v);
			ret ^= g[v];
		}
		if(!ret) printf("Case %d: Bob\n", cs);
		else printf("Case %d: Alice\n", cs);
	}
	return 0;
}
