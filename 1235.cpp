#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long i64;

vector< i64 > Lt, Rt;
i64 a[20];

void generate(i64 sum, int st, int en, vector< i64 > &v) {
	if(st == en) { v.push_back(sum); return; }
	for(int i = 0; i < 3; i++) generate(sum + a[st] * i, st + 1, en, v);
}

int main() {
	int test, cs, m, n, i, mid, sz;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &n, &m);
		for(i = 0; i < n; i++) scanf("%lld", &a[i]);
		Lt.clear(); Rt.clear();
		mid = n >> 1;
		generate(0, 0, mid, Lt);
		generate(0, mid, n, Rt);
		sort(Lt.begin(), Lt.end());
		sz = Rt.size();
		for(i = 0; i < sz; i++) {
			if(m >= Rt[i]) {
				if(*lower_bound(Lt.begin(), Lt.end(), m - Rt[i]) == m - Rt[i]) break;
			}
		}
		if(i == sz) printf("Case %d: No\n", cs);
		else printf("Case %d: Yes\n", cs);
	}
	return 0;
}
