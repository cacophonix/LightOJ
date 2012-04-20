#include <cstdio>

const int NMAX = 1 << 18;
const int TMAX = 1 << 19;

int a[NMAX], t[TMAX], N;

void init(int node, int i, int j) {
	if(i == j) {
		if(i < N) t[node] = 1;
		else t[node] = 0;
		return;
	}
	int mid = (i + j) >> 1, lnode = node << 1, rnode = lnode + 1;
	init(lnode, i, mid);
	init(rnode, mid + 1, j);
	t[node] = t[lnode] + t[rnode];
}

void update(int node, int i, int j, int pos) {
	if(i == j) {
		t[node] = 1;
		return;
	}
	int mid = (i + j) >> 1, lnode = node << 1, rnode = lnode + 1;
	if(pos <= mid) update(lnode, i, mid, pos);
	else update(rnode, mid + 1, j, pos);
	t[node] = t[lnode] + t[rnode];
}

int query(int node, int i, int j, int pos) {
	if(i == j) {
		t[node] = 0;
		return a[i];
	}
	int ret, mid = (i + j) >> 1, lnode = node << 1, rnode = lnode + 1;
	if(pos <= t[lnode]) ret = query(lnode, i, mid, pos);
	else ret = query(rnode, mid + 1, j, pos - t[lnode]);
	t[node] = t[lnode] + t[rnode];
	return ret;
}

int main() {
	int test, cs, n, q, i, x;
	char s[2];
	//freopen("in.txt", "r", stdin);
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &n, &q);
		for(i = 0; i < n; i++) scanf("%d", a + i);
		N = n;
		printf("Case %d:\n", cs);
		init(1, 0, n + q - 1);
		for(i = 0; i < q; i++) {
			scanf("%s %d", s, &x);
			switch(s[0]) {
				case 'c' :
					if(x <= t[1]) printf("%d\n", query(1, 0, n + q - 1, x));
					else printf("none\n");
				break;
				case 'a' :
					update(1, 0, n + q - 1, N);
					a[N++] = x;
				break;
			}
		}
	}
	return 0;
}