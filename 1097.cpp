#include <cstdio>

const int MAXNUM = 1429431;
const int MAX = 476479;
const int NIL = 0;

int nodes, root, total;
int Left[MAX], Right[MAX], Parent[MAX], Size[MAX], Keys[MAX], Lucky[100001];

int build(int a, int b) {
	if(a > b) return NIL;
	if(a == b) { nodes++; Left[nodes] = Right[nodes] = NIL; Size[nodes] = 1; return nodes; }
	int c = (a+b)>>1, t = build(a, c-1);
	Left[++nodes] = t; t = nodes; Right[t] = build(c+1, b);
	Size[t] = Size[Left[t]] + Size[Right[t]] + 1;
	Parent[Left[t]] = Parent[Right[t]] = t;
	return t;
}

void remove(int x) {
	int y;
	if(Left[x] != NIL && Right[x] != NIL) {
		if(Size[Right[x]] >= Size[Left[x]]) for(y = Right[x]; Left[y] != NIL; y = Left[y]);
		else for(y = Left[x]; Right[y] != NIL; y = Right[y]);
		Keys[x] = Keys[y];
		x = y;
	}
	if(Left[x] == NIL && Right[x] == NIL) {
		if(Left[Parent[x]] == x) Left[Parent[x]] = NIL;
		else Right[Parent[x]] = NIL;
	}
	else {
		y = (Left[x] == NIL) ? Right[x] : Left[x];
		if(Parent[x] == NIL) {
			Parent[root = y] = NIL;
			return;
		}
		if(Left[Parent[x]] == x) Left[Parent[x]] = y;
		else Right[Parent[x]] = y;
		Parent[y] = Parent[x];
	}
	for(x = Parent[x]; x != NIL; x = Parent[x]) Size[x]--;
}

int find(int k) {
	int x = root;
	while(true) {
		if(k < Size[Left[x]]) x = Left[x];
		else if(k > Size[Left[x]]) k -= Size[Left[x]] + 1, x = Right[x];
		else return x;
	}
	return NIL;
}

void inorder(int u) {
	if(Left[u] != NIL) inorder(Left[u]);
	Lucky[++total] = Keys[u];
	if(Right[u] != NIL) inorder(Right[u]);
}

int main() {
	int test, cs, n, i, j, k;
	for(i = j = 0; ; j+=6) {
		if(j + 1 > MAXNUM) break;
		Keys[++i] = j + 1;
		if(j + 3 > MAXNUM) break;
		Keys[++i] = j + 3;
	}
	Parent[root = build(1, i)] = NIL;
	for(k = 2; k < Size[root]; k++) {
		j = Keys[find(k)]-1;
		if (j >= Size[root]) break;
		for(i = j; i < Size[root]; i += j) remove(find(i));
	}
	inorder(root);
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		printf("Case %d: %d\n", cs, Lucky[n]);
	}
	return 0;
}