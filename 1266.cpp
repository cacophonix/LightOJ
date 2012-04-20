#include <cstdio>

const int MAX = 1002;

int bit[MAX][MAX], cs;
unsigned char vis[MAX][MAX];

void update(int x, int y, int v) {
	int y1;
	while(x < MAX) {
		y1 = y;
		while(y1 < MAX) {
			if((vis[x][y1]>>4) != cs) {
				vis[x][y1] &= 0x0f;
				vis[x][y1] |= (cs << 4);
				bit[x][y1] = 0;
			}
			bit[x][y1] += v;
			y1 += (y1 & -y1);
		}
		x += (x & -x);
	}
}

int readsum(int x, int y) {
	int v = 0, y1;
	while(x > 0) {
		y1 = y;
		while(y1 > 0) {
			if((vis[x][y1]>>4) == cs) v += bit[x][y1];
			y1 -= (y1 & -y1);
		}
		x -= (x & -x);
	}
	return v;
}

int main() {
	int test, q, x1, y1, x2, y2, type, ans;
	//freopen("in.txt", "r", stdin);
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &q);
		printf("Case %d:\n", cs);
		while(q--) {
			scanf("%d", &type);
			if(type == 0) {
				scanf("%d %d", &x1, &y1);
				x1++, y1++;
				if((vis[x1][y1]&15) != cs) {
					vis[x1][y1] &= 0xf0;
					vis[x1][y1] |= cs;
					update(x1, y1, 1);
				}
			}
			else {
				scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
				x1++, y1++, x2++, y2++;
				ans = readsum(x2, y2) - readsum(x1-1, y2) - readsum(x2, y1-1) + readsum(x1-1, y1-1);
				printf("%d\n", ans);
			}
		}
	}
	return 0;
}