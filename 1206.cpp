#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

typedef struct { int start, duration, sx, sy, ex, ey; } Booking;

const int MAX = 512;

Booking bookings[MAX];
vector< int > G[MAX];
char visited[MAX];
int Left[MAX], Right[MAX];
 
bool dfs(int u) {
	if(visited[u]) return false;
	visited[u] = true;
	int len = G[u].size(), i, v;
	for(i=0; i<len; i++) {
		v = G[u][i];
		if(Right[v]==-1) {
			Right[v] = u, Left[u] = v;
			return true;
		}
	}
	for(i=0; i<len; i++) {
		v = G[u][i];
		if(dfs(Right[v])) {
			Right[v] = u, Left[u] = v;
			return true;
		}
	}
	return false;
}
 
int match(int n) {
	int i, ret = 0;
	bool done;
	memset(Left, -1, sizeof(int) * n);
	memset(Right, -1, sizeof(int) * n);
	do {
		done = true;
		memset(visited, 0, sizeof(char) * n);
		for(i=0; i<n; i++) {
			if(Left[i]==-1 && dfs(i)) {
				done = false;
			}
		}
	} while(!done);
	for(i=0; i<n; i++) ret += (Left[i]!=-1);
	return ret;
}

inline bool reachable(int u, int v) {
	int tms = bookings[u].start + bookings[u].duration;
	int x = bookings[u].ex - bookings[v].sx; if(x < 0) x = -x;
	int y = bookings[u].ey - bookings[v].sy; if(y < 0) y = -y;
	return tms + x + y < bookings[v].start;
}

int main() {
	int test, cs, m, i, j, sx, sy, ex, ey, hh, mm, ans;	
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &m);
		for(i = 0; i < m; i++) {
			scanf("%d:%d %d %d %d %d", &hh, &mm, &sx, &sy, &ex, &ey);
			bookings[i].start = hh * 60 + mm;
			bookings[i].duration = (sx<ex ? ex-sx : sx-ex) + (sy<ey ? ey-sy : sy-ey);
			bookings[i].sx = sx, bookings[i].sy = sy;
			bookings[i].ex = ex, bookings[i].ey = ey;
		}
		for(i = 0; i < m; i++) {
			G[i].clear();
			for(j = 0; j < m; j++) {
				if(reachable(i, j)) G[i].push_back(j);
			}
		}
		match(m);
		memset(visited, 0, sizeof(char) * m);
		for(ans = i = 0; i < m; i++) {
			if(!visited[i]) {
				for(j = i; j > -1 && !visited[j]; j = Left[j]) {
					visited[j] = 1;
				}
				if(j <= -1 || !visited[j]) ans++;
			}
		}
		printf("Case %d: %d\n", cs, ans);
	}
	return 0;
}