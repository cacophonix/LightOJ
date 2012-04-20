#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int MAX = 1001;

vector< int > G[MAX];
int cnt[MAX], flag[MAX], st[100], flg;

void bfs(int s) {
	int u, v, i, sz;
	queue< int > Q;
	Q.push(s);
	cnt[s]++; flag[s] = flg;
	while(!Q.empty()) {
		u = Q.front(); Q.pop();
		sz = G[u].size();
		for(i = 0; i < sz; i++) {
			v = G[u][i];
			if(flag[v] != flg) {
				flag[v] = flg;
				cnt[v]++;
				Q.push(v);
			}
		}
	}
}

int main() {
	int test, cs, n, k, e, i, u, v, ans;
	scanf("%d", &test);
	for(cs = flg = 1; cs <= test; cs++) {
		scanf("%d %d %d", &k, &n, &e);
		for(i = 1; i <= n; i++) {
			G[i].clear();
			cnt[i] = 0;
		}
		for(i = 0; i < k; i++) scanf("%d", &st[i]);
		for(i = 0; i < e; i++) {
			scanf("%d %d", &u, &v);
			G[u].push_back(v);
		}
		for(i = 0; i < k; i++) {
			bfs(st[i]);
			flg++;
		}
		for(ans = 0, i = 1; i <= n; i++) {
			if(cnt[i] == k) ans++;
		}
		printf("Case %d: %d\n", cs, ans);
	}
	return 0;
}