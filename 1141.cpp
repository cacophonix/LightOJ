#include <cassert>
#include <cstdio>
#include <queue>
using namespace std;

const int MAXS = 101, MAXT = 1001;

int primes[256], prlen;
int factors[MAXT][4], deg[MAXT], d[MAXT], flag[MAXT];
int test, cs;

void factor() {
	int i, j;
	for(i = 4; i < MAXT; i+=2) factors[i][deg[i]++] = 2;
	for(i = 3; i < MAXT; i+=2) if(!deg[i]) {
		for(j = i + i; j < MAXT; j += i) factors[j][deg[j]++] = i;
	}
}

int bfs(int s, int t) {
	queue< int > Q;
	int i, u, v;
	if(s > t) return -1;
	if(s == t) return 0;
	Q.push(s); d[s] = 0; flag[s] = cs;
	while(!Q.empty()) {
		u = Q.front(); Q.pop();
		for(i = 0; i < deg[u]; i++) {
			v = u + factors[u][i];
			if(v <= t && flag[v] != cs) {
				d[v] = d[u] + 1;
				if(v == t) return d[v];
				flag[v] = cs;
				Q.push(v);
			}
		}
	}
	return -1;
}

int main() {
	int s, t;
	factor();
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &s, &t);
		printf("Case %d: %d\n", cs, bfs(s, t));
	}
	return 0;
}
