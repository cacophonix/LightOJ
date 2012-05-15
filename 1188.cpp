#include <cstdio>
#include <cstring>

const int MAX = 100001;
const int TMAX = 1 << 18;

struct Query {
	int i, j, next, ans;
};

int a[MAX], last[MAX], next[MAX];
Query Q[MAX];
int T[TMAX];

void update(int node, int i, int j, int p, int val) {
	if(i == j) { T[node] += val; return; }
	int mid = (i + j) >> 1, lt = node << 1, rt = lt | 1;
	if(p <= mid) update(lt, i, mid, p, val);
	else update(rt, mid + 1, j, p, val);
	T[node] = T[lt] + T[rt];
}

int query(int node, int i, int j, int p, int q) {
	if(i == p && j == q) return T[node];
	int mid = (i + j) >> 1, lt = node << 1, rt = lt | 1;
	if(q <= mid) return query(lt, i, mid, p, q);
	else if(p > mid) return query(rt, mid + 1, j, p, q);
	else return query(lt, i, mid, p, mid) + query(rt, mid + 1, j, mid + 1, q);
}

int main() {
	int test, cs, n, q, i, j, x, y;
	//freopen("in.txt", "r", stdin);
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &n, &q);
		memset(T, 0, sizeof T);
		memset(next, -1, sizeof next);
		memset(last, -1, sizeof last);
		for(i = 0; i < n; i++) scanf("%d", a + i);
		for(i = 0; i < q; i++) {
			scanf("%d %d", &x, &y);
			x--, y--;
			Q[i].i = x; Q[i].j = y;
			Q[i].next = next[y];
			next[y] = i;
		}
		for(i = 0; i < n; i++) {
			if(last[a[i]] > -1) update(1, 0, n-1, last[a[i]], -1);
			update(1, 0, n-1, last[a[i]] = i, 1);
			for(j = next[i]; j > -1; j = Q[j].next) Q[j].ans = query(1, 0, n-1, Q[j].i, Q[j].j);
		}
		printf("Case %d:\n", cs);
		for(i = 0; i < q; i++) printf("%d\n", Q[i].ans);
	}
	return 0;
}