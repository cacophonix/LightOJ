#include <cstring>
#include <cstdio>

const int MAX = 100001;

int bit[MAX], a[MAX], n;

void update(int idx, int val) {
	while(idx <= n) {
		bit[idx] += val;
		idx += (idx & -idx);
	}
}

int query(int idx) {
	int sum = 0;
	while(idx > 0) {
		sum += bit[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

int main() {
	int test, cs, q, i, j, c;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &n, &q);
		memset(bit, 0, sizeof(int)*(n+1));
		for(i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			update(i, a[i]);
		}
		printf("Case %d:\n", cs);
		while(q--) {
			scanf("%d", &c);
			if(c == 1) {
				scanf("%d", &i); i++;
				update(i, -a[i]);
				printf("%d\n", a[i]);
				a[i] = 0;
			}
			else if(c == 2) {
				scanf("%d %d", &i, &j); i++;
				update(i, j);
				a[i] += j;
			}
			else {
				scanf("%d %d", &i, &j); j++;
				printf("%d\n", query(j) - query(i));
			}
		}
	}
	return 0;
}
