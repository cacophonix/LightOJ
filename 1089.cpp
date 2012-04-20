#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 150000;

int bit[MAX + 1], mx;
int ival[50000][2], qval[50000];
pair< int, int > a[MAX];

void update(int id, int val) {
	while(id <= mx) {
		bit[id] += val;
		id += (id & -id);
	}
}

int read(int id) {
	int ret = 0;
	while(id > 0) {
		ret += bit[id];
		id -= (id & -id);
	}
	return ret;
}

int main() {
	int test, cs, n, q, i, j, k, u, v;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &n, &q);
		for(k = i = 0; i < n; i++) {
			scanf("%d %d", &u, &v);
			ival[i][0] = u, ival[i][1] = v;
			a[k++] = pair< int, int >(u, i<<1);
			a[k++] = pair< int, int >(v, (i<<1)+1);
		}
		for(i = 0; i < q; i++) {
			scanf("%d", &u);
			qval[i] = u;
			a[k++] = pair< int, int >(u, (n<<1)+i);
		}
		sort(a, a + k);
		for(i = 0; i < k; i++) {
			if(!i) j = 1;
			else if(a[i].first != a[i-1].first) j++;
			if(a[i].second >= (n << 1)) qval[a[i].second - (n << 1)] = j;
			else {
				if(a[i].second & 1) ival[a[i].second >> 1][1] = j;
				else ival[a[i].second >> 1][0] = j;
			}
		}
		mx = j;
		memset(bit, 0, sizeof(int) * (j+1));
		for(i = 0; i < n; i++) {
			update(ival[i][0], 1);
			update(ival[i][1]+1, -1);
		}
		printf("Case %d:\n", cs);
		for(i = 0; i < q; i++) printf("%d\n", read(qval[i]));
	}
	return 0;
}