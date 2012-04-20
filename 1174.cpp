#include <cstdio>
#include <cstring>

#define N 101

int imin(const int tl, const int tr) { return (tl == 0 || tl > tr)? tr : tl; }

int imax(const int tl, const int tr) { return (tl > tr)? tl : tr; }

int main() {
	int i, t, n, r, a, b, c, s, e, max_value, map[N][N];
	scanf("%d", &t);
	for(c = 1; c <= t; c++) {
		scanf("%d%d", &n, &r);
		memset(map, 0, sizeof(map));
		for(i = 0; i < r; i++) {
			scanf("%d%d", &a, &b);
			map[a][b] = map[b][a] = 1;
		}
		scanf("%d%d", &s, &e);
		for(i = 0; i < n; i++)
			for(a = 0; a < n; a++)
				for(b = 0; b < n; b++)
					if(map[a][i] && map[i][b])
						map[a][b] = imin(map[a][b], map[a][i] + map[i][b]);
		for(i = 0; i < n; i++) map[i][i] = 0;
		max_value = 0;
		for(i = 0; i < n; i++) max_value = imax(max_value, map[s][i] + map[i][e]);
		printf("Case %d: %d\n", c, max_value);
	}
	return 0;
}
