#include <cstdio>
#include <algorithm>
using namespace std;

const int NMAX = 1<<17;
const int TMAX = 1<<18;

typedef struct { int lval, lmax, rval, rmax, tmax; } NODE;

NODE T[TMAX];
int a[NMAX];

void init(int Node, int i, int j) {
	if(i == j) {
		T[Node].lval = T[Node].rval = a[i];
		T[Node].lmax = T[Node].rmax = T[Node].tmax = 1;
		return;
	}
	int mid = (i + j) >> 1, Left = Node << 1, Right = Left + 1;
	init(Left, i, mid);
	init(Right, mid + 1, j);
	T[Node].lval = T[Left].lval;
	T[Node].rval = T[Right].rval;
	if(T[Left].lval == T[Right].lval) T[Node].lmax = T[Left].lmax + T[Right].lmax;
	else T[Node].lmax = T[Left].lmax;
	if(T[Left].rval == T[Right].rval) T[Node].rmax = T[Left].rmax + T[Right].rmax;
	else T[Node].rmax = T[Right].rmax;
	T[Node].tmax = max(T[Left].tmax, T[Right].tmax);
	if(T[Left].rval == T[Right].lval) T[Node].tmax = max(T[Node].tmax, T[Left].rmax + T[Right].lmax);
}

NODE query(int Node, int i, int j, int qi, int qj) {
	if(i == qi && j == qj) return T[Node];
	int mid = (i + j) >> 1, Left = Node << 1, Right = Left + 1;
	if(qj <= mid) return query(Left, i, mid, qi, qj);
	else if(qi > mid) return query(Right, mid + 1, j, qi, qj);
	else {
		NODE lt = query(Left, i, mid, qi, mid);
		NODE rt = query(Right, mid + 1, j, mid + 1, qj);
		NODE res;
		res.lval = lt.lval, res.rval = rt.rval;
		if(lt.lval == rt.lval) res.lmax = lt.lmax + rt.lmax;
		else res.lmax = lt.lmax;
		if(lt.rval == rt.rval) res.rmax = lt.rmax + rt.rmax;
		else res.rmax = rt.rmax;
		res.tmax = max(lt.tmax, rt.tmax);
		if(lt.rval == rt.lval) res.tmax = max(res.tmax, lt.rmax + rt.lmax);
		return res;
	}
}

int main() {
	int test, cs, i, j, n, c, q;
	NODE ans;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d %d", &n, &c, &q);
		for(i = 0; i < n; i++) scanf("%d", a + i);
		init(1, 0, n-1);
		printf("Case %d:\n", cs);
		while(q--) {
			scanf("%d %d", &i, &j);
			ans = query(1, 0, n-1, i-1, j-1);
			printf("%d\n", ans.tmax);
		}
	}
	return 0;
}