#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1 << 16;
const int MAXL = 16;

int n, stp, mv, suffix[MAXN], tmp[MAXN];
int sum[MAXN], cnt[MAXN], rank[MAXL][MAXN];
char str[MAXN];

inline bool equal(const int &u, const int &v){
	if(!stp) return str[u] == str[v];
	if(rank[stp-1][u] != rank[stp-1][v]) return false;
	int a = u + mv < n ? rank[stp-1][u+mv] : -1;
	int b = v + mv < n ? rank[stp-1][v+mv] : -1;
	return a == b;
}

void update(){
	int i, rnk;
	for(i = 0; i < n; i++) sum[i] = 0;
	for(i = rnk = 0; i < n; i++) {
		suffix[i] = tmp[i];
		if(i && !equal(suffix[i], suffix[i-1])) {
			rank[stp][suffix[i]] = ++rnk;
			sum[rnk+1] = sum[rnk];
		}
		else rank[stp][suffix[i]] = rnk;
		sum[rnk+1]++;
	}
}

void Sort() {
	int i;
	for(i = 0; i < n; i++) cnt[i] = 0;
	memset(tmp, -1, sizeof tmp);
	for(i = 0; i < mv; i++){
		int idx = rank[stp - 1][n - i - 1];
		int x = sum[idx];
		tmp[x + cnt[idx]] = n - i - 1;
		cnt[idx]++;
	}
	for(i = 0; i < n; i++){
		int idx = suffix[i] - mv;
		if(idx < 0)continue;
		idx = rank[stp-1][idx];
		int x = sum[idx];
		tmp[x + cnt[idx]] = suffix[i] - mv;
		cnt[idx]++;
	}
	update();
	return;
}

inline bool cmp(const int &a, const int &b){
	if(str[a]!=str[b]) return str[a]<str[b];
	return false;
}

void SortSuffix() {
	int i;
	for(i = 0; i < n; i++) tmp[i] = i;
	sort(tmp, tmp + n, cmp);
	stp = 0;
	update();
	++stp;
	for(mv = 1; mv < n; mv <<= 1) {
		Sort();
		stp++;
	}
	stp--;
	for(i = 0; i <= stp; i++) rank[i][n] = -1;
}

inline int lcp(int u, int v) {
	if(u == v) return n - u;
	int ret, i;
	for(ret = 0, i = stp; i >= 0; i--) {
		if(rank[i][u] == rank[i][v]) {
			ret += 1<<i;
			u += 1<<i;
			v += 1<<i;
		}
	}
	return ret;
}

int main(){
	int test, cs, i, res, p, q, mn, mx, x;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%s %d %d", str, &p, &q);
		n = strlen(str);
		SortSuffix();
		res = min(n - suffix[0], q) - p + 1;
		if(res < 0) res = 0;
		for(i = 1; i < n; i++) {
			mn = max(p, 1 + lcp(suffix[i-1], suffix[i]));
			mx = min(q, n - suffix[i]);
			x = mx - mn + 1;
			if(x > 0) res += x;
		}
		printf("Case %d: %d\n", cs, res);
	}
	return 0;
}