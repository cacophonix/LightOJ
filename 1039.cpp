#include <cstdio>

const int MAX = 1 << 15;

static int flagv, head, tail;

char flag[MAX], vis[MAX];
int Q[MAX], D[MAX], tr[2] = {1, 25};

inline void tochar(int n, char *a) {
	a[2] = n & 31; n >>= 5; a[1] = n & 31; n >>= 5; a[0] = n;
}

inline int toint(char *s) {
	return (s[0]<<10) | (s[1]<<5) | s[2];
}

int bfs(int st, int en) {
	int u, v, i, j;
	char buff[4], c;
	if(flag[st]==flagv || flag[en]==flagv) return -1;
	if(st == en) return 0;
	head = tail = 0; Q[tail++] = st; D[st] = 0; vis[st] = flagv;
	while(head < tail) {
		u = Q[head++]; tochar(u, buff);
		for(i = 0; i < 3; i++) {
			c = buff[i];
			for(j = 0; j < 2; j++) {
				buff[i] = c + tr[j];
				if(buff[i] >= 26) buff[i] -= 26;
				v = toint(buff);
				if(vis[v] != flagv) {
					vis[v] = flagv;
					D[v] = D[u] + 1;
					if(v != en) Q[tail++] = v;
					else return D[v];
				}
			}
			buff[i] = c;
		}
	}
	return -1;
}

int main() {
	int test, cs, i, n, p, q, r;
	char st[4], en[4], buff[4][32];
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		flagv = cs;
		scanf("%s %s %d", st, en, &n);
		for(i = 0; i < n; i++) {
			scanf("%s %s %s", buff[0], buff[1], buff[2]);
			for(p = 0; buff[0][p]; p++) {
				for(q = 0; buff[1][q]; q++) {
					for(r = 0; buff[2][r]; r++) {
						buff[3][0] = buff[0][p] - 'a';
						buff[3][1] = buff[1][q] - 'a';
						buff[3][2] = buff[2][r] - 'a';
						flag[toint(buff[3])] = flagv;
					}
				}
			}
		}
		for(i = 0; i < 3; i++) st[i] -= 'a', en[i] -= 'a';
		r = bfs(toint(st), toint(en));
		printf("Case %d: %d\n", cs, r);
	}
	return 0;
}