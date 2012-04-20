#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 100001;
const int MOD = 1000000007;

typedef struct { int n, i; } Data;

Data d[MAX];
int a[MAX], BIT[MAX], mx;

inline bool comp(const Data &a, const Data &b) {
	return a.n < b.n;
}

int compress(int n) {
	int i, k;
	sort(d, d + n, comp);
	a[d[0].i] = 1;
	for(i = k = 1; i < n; i++) {
		if(d[i-1].n == d[i].n) a[d[i].i] = k;
		else a[d[i].i] = ++k;
	}
	return k;
}

int read(int idx) {
	int sum = 0;
	while(idx > 0) {
		sum += BIT[idx];
		if(sum >= MOD) sum -= MOD;
		idx -= (idx & -idx);
	}
	return sum;
}

void update(int idx, int val) {
	if(val >= MOD) val -= MOD;
	while(idx <= mx) {
		BIT[idx] += val;
		if(BIT[idx] >= MOD) BIT[idx] -= MOD;
		idx += (idx & -idx);
	}
}

int main() {
	int test, cs, n, i, sum, p, q;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		for(i = 0; i < n; i++) {
			scanf("%d", &d[i].n);
			d[i].i = i;
		}
		mx = compress(n);
		memset(BIT, 0, sizeof(int)*(mx+1));
		for(i = 0; i < n; i++) {
			p = read(a[i] - 1);
			update(a[i], p + 1);
		}
		for(i = 1, sum = q = 0; i <= mx; i++) {
			p = read(i);
			if(p < q) sum += p - q + MOD;
			else sum += p - q;
			if(sum >= MOD) sum -= MOD;
			q = p;
		}
		printf("Case %d: %d\n", cs, sum);
	}
	return 0;
}
