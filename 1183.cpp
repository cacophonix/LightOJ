#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct { int sum, carry; } TreeNode;

TreeNode nodes[1 << 18];

void init(int node, int i, int j) {
	nodes[node].sum = 0, nodes[node].carry = -1;
	if(i == j) return;
	int mid = (i + j) >> 1, lnode = node << 1, rnode = lnode + 1;
	init(lnode, i, mid);
	init(rnode, mid + 1, j);
}

void update(int node, int i, int j, int qi, int qj, int carry, int v) {
	// propagation
	if(carry > -1) {
		nodes[node].carry = carry;
		nodes[node].sum = (j - i + 1) * carry;
	}
	else carry = nodes[node].carry;
	// is this the correct segment?
	qi = max(i, qi); qj = min(j, qj);
	if(qi > qj) return;
	// target segment reached
	if(i == qi && j == qj) {
		nodes[node].carry = v;
		nodes[node].sum = (j - i + 1) * v;
		return;
	}
	// recursively update
	int mid = (i + j) >> 1, lnode = node << 1, rnode = lnode + 1;
	update(lnode, i, mid, qi, qj, carry, v);
	update(rnode, mid + 1, j, qi, qj, carry, v);
	nodes[node].carry = -1;
	nodes[node].sum = nodes[lnode].sum + nodes[rnode].sum;
}

int query(int node, int i, int j, int qi, int qj, int carry) {
	if(carry > -1) {
		nodes[node].carry = carry;
		nodes[node].sum = (j - i + 1) * carry;
	}
	else carry = nodes[node].carry;
	qi = max(i, qi); qj = min(j, qj);
	if(qi > qj) return 0;
	if(i == qi && j == qj) return nodes[node].sum;
	int mid = (i + j) >> 1, lnode = node << 1, rnode = lnode + 1;
	nodes[node].carry = -1;
	return query(lnode, i, mid, qi, qj, carry) + query(rnode, mid + 1, j, qi, qj, carry);
}

int gcd(int a, int b) {
	while(b) b ^= a ^= b ^= a %= b;
	return a;
}

int main() {
	int test, cs, n, q, ch, i, j, k, g, sum, v;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &n, &q);
		init(1, 0, n-1);
		printf("Case %d:\n", cs);
		while(q--) {
			scanf("%d", &ch);
			if(ch == 1) {
				scanf("%d %d %d", &i, &j, &v);
				update(1, 0, n-1, i, j, -1, v);
			}
			else {
				scanf("%d %d", &i, &j);
				sum = query(1, 0, n-1, i, j, -1);
				k = j - i + 1;
				g = gcd(sum, k);
				sum /= g, k /= g;
				if(sum == 0 || k == 1) printf("%d\n", sum);
				else printf("%d/%d\n", sum, k);
			}
		}
	}
	return 0;
}