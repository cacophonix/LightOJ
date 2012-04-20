#include <cstdio>
#include <cassert>
#include <cstring>
#include <queue>
#include <vector>
#include <string>
using namespace std;

typedef pair< int, int > pii;

int indeg[26], outdeg[26], color[26], cnt1, cnt2, len[1001];
int found[26], g[26][26];
char word[1001][26];
vector< int > path;
vector< int > GS[26][26];
vector< pii > G[26];

bool isConnected() {
	int i, j;
	queue< int > Q;
	for(i=0; i<26; i++) color[i] = (found[i]? 0 : 2);
	for(i=0; color[i]; i++); color[i] = 1;
	Q.push(i);
	while(!Q.empty()) {
		i = Q.front(); Q.pop();
		for(j=0; j<26; j++) {
			if((g[i][j] || g[j][i]) && !color[j]) {
				Q.push(j);
				color[j] = 1;
			}
		}
		color[i] = 2;
	}
	for(i=0; i<26; i++)
		if(color[i]!=2)
			return false;
	return true;
}

bool hasEularPath() {
	if(!isConnected()) return false;
	int i;
	for(i=cnt1=cnt2=0; i<26; i++) {
		if(outdeg[i]-indeg[i]==1) cnt1++;
		else if(indeg[i]-outdeg[i]==1) cnt2++;
		else if(indeg[i]!=outdeg[i]) return false;
	}
	if(cnt1+cnt2==0 || (cnt1==1 && cnt2==1)) return true;
	return false;
}

void findCycle(int u) {
	for(int i = 0; i < G[u].size(); i++) {
		if(G[u][i].second == 1) {
			G[u][i].second = 0;
			findCycle(G[u][i].first);
		}
	}
	path.push_back(u);
}

int main() {
	int test, cs, n, u, v, i, j, first;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		memset(indeg, 0, sizeof indeg);
		memset(outdeg, 0, sizeof outdeg);
		memset(g, 0, sizeof g);
		memset(found, 0, sizeof found);
		
		for(i = 0; i < 26; i++) {
			for(j = 0; j < 26; j++) GS[i][j].clear();
			G[i].clear();
		}
		path.clear();
		
		for(i = 0; i < n; i++) {
			scanf("%s", word[i]);
			len[i] = strlen(word[i]);
			outdeg[u = word[i][0]-'a']++;
			indeg[v = word[i][len[i]-1]-'a']++;
			g[u][v] = found[u] = found[v] = 1;
			GS[u][v].push_back(i);
			G[u].push_back(pii(v, 1));
		}
		
		if(hasEularPath()) {
			printf("Case %d: Yes\n", cs);
			for(i = 0; i < 26; i++) {
				if(outdeg[i] > indeg[i]) break;
			}
			if(i == 26) for(i = 0; !outdeg[i]; i++);
			findCycle(i);
			j = path.back(); first = 0;
			for(i = path.size()-2; i >= 0; i--) {
				if(first) printf(" ");
				printf("%s", word[ GS[j][path[i]].back() ] );
				GS[j][path[i]].pop_back();
				j = path[i];
				first = 1;
			}
			printf("\n");
		}
		else printf("Case %d: No\n", cs);
	}
	return 0;
}
