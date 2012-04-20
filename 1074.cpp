#include <cstdio>
#include <cstring>

#define MAX 256
#define INF 0x3f3f3f3f
#define cube(x) (x)*(x)*(x)

int G[MAX][MAX], deg[MAX];
int busy[MAX], cost[MAX], w[MAX][MAX];
int cs, flag[MAX], reach[MAX];

void bellman(int n) {
   int i, u, v, pass, done = 0;
   memset(cost, 0x3f, n * sizeof(int));
   cost[0] = 0;
   for(pass = 0; pass < n && !done; pass++) {
      for(u = 0, done = 1; u < n; u++) {
         for(i = 0; i < deg[u]; i++) {
            v = G[u][i];
            if(cost[v] > cost[u] + w[u][v]) {
               done = 0;
               cost[v] = cost[u] + w[u][v];
            }
         }
      }
   }
}

void dfs(int u) {
   int i, v;
   flag[u] = cs;
   for(i = 0; i < deg[u]; i++) {
      v = G[u][i];
      if(flag[v] != cs) {
         dfs(v);
      }
   }
}

void checkcycle(int n) {
   int i, u, v;
   for(u = 0; u < n; u++) {
      for(i = 0; i < deg[u]; i++) {
         v = G[u][i];
         if(cost[v] > cost[u] + w[u][v]) dfs(v);
      }
   }
}

void dfs2(int u) {
	int i, v;
	reach[u] = cs;
	for(i = 0; i < deg[u]; i++) {
		v = G[u][i];
		if(reach[v] != cs) dfs2(v);
	}
}

int main() {
   int n, i, e, u, v, q, test; cs = 1;
   scanf("%d", &test);
   while(test--) {
      scanf("%d", &n);
      for(i = 0; i < n; i++) scanf("%d", busy + i);
      memset(deg, 0, n * sizeof(int));
      scanf("%d", &e);
      for(i = 0; i < e; i++) {
         scanf("%d %d", &u, &v);
         u--; v--;
         w[u][v] = cube(busy[v] - busy[u]);
         G[u][deg[u]++] = v;
      }
      bellman(n);
      checkcycle(n);
      dfs2(0);
      scanf("%d", &q);
      printf("Case %d:\n", cs);
      while(q--) {
         scanf("%d", &v); v--;
         if(v < 0 || v >= n || reach[v]!=cs || cost[v] < 3 || flag[v]==cs) puts("?");
         else printf("%d\n", cost[v]);
      }
      cs++;
   }
   return 0;
}
