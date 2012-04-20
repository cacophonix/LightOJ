#include <cstdio>
#include <cstring>

char str[1 << 17];
char Tree[1 << 18];

void update(int Node, int i, int j, int ri, int rj) {
	if(i == ri && j == rj) {
		Tree[Node] ^= 1;
		return;
	}
	int mid = (i + j) >> 1, Left = Node << 1, Right = Left + 1;
	if(rj <= mid) update(Left, i, mid, ri, rj);
	else if(ri > mid) update(Right, mid + 1, j, ri, rj);
	else {
		update(Left, i, mid, ri, mid);
		update(Right, mid + 1, j, mid + 1, rj);
	}
}

char query(int Node, int i, int j, int idx, int inv) {
	inv ^= Tree[Node];
	if(i == j) {
		if(inv & 1) return ((str[i]-'0')^1) + '0';
		else return str[i];
	}
	int mid = (i + j) >> 1, Left = Node << 1, Right = Left + 1;
	if(idx <= mid) return query(Left, i, mid, idx, inv);
	else return query(Right, mid + 1, j, idx, inv);
}

int main() {
	int test, cs, n, q, i, j;
	char comm[2];
	freopen("in.txt", "r", stdin);
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		printf("Case %d:\n", cs);
		memset(Tree, 0, sizeof Tree);
		scanf("%s %d", str, &q);
		n = strlen(str);
		while(q--) {
			scanf("%s", comm);
			switch(comm[0]) {
				case 'I':
					scanf("%d %d", &i, &j);
					update(1, 0, n-1, i-1, j-1);
				break;
				case 'Q':
					scanf("%d", &i);
					printf("%c\n", query(1, 0, n-1, i-1, 0));
				break;
			}
		}
	}
	return 0;
}