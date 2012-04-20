#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x7f7f7f7f;

int overlap[16][128], idx[16], len[16], dp[16][1<<16], flag[16][1<<16], flagv, junction[16][16], cont[16][16];
char str[16][128], valid[16];

void computeOverlap(int id, char *pattern) {
	overlap[id][0] = -1;
	for(int i=0; pattern[i]; i++) {
		overlap[id][i+1] = overlap[id][i] + 1;
		while(overlap[id][i+1] > 0 && pattern[i] != pattern[overlap[id][i+1]-1]) {
			overlap[id][i+1] = overlap[id][overlap[id][i+1]-1] + 1;
		}
	}
}

bool contained(int pat, int tar) {
	int i, j;
	for(i = j = 0; str[tar][i]; i++) {
		while(true) {
			if(str[tar][i] == str[pat][j]) {
				j++;
				if(!str[pat][j]) return true;
				break;
			}
			else if(!j) break;
			else j = overlap[pat][j];
		}
	}
	return false;
}

bool comp(int a, int b) {
	if(valid[a] != valid[b]) return valid[a] > valid[b];
	return strcmp(str[a], str[b]) < 0;
}

int calcjunc(int suf, int pre) {
	int k = min(len[idx[suf]], len[idx[pre]]) - 1, p;
	for(p = k; p >= 1; p--) {
		if(!strncmp(&str[idx[suf]][len[idx[suf]]-p], str[idx[pre]], p)) return p;
	}
	return p;
}

int solve(int p, int n, int mask) {
	if(mask == (1<<n) - 1) return len[idx[p]];
	if(flag[p][mask] == flagv) return dp[p][mask];
	flag[p][mask] = flagv;
	int &ret = dp[p][mask]; ret = INF;
	for(int i = 0; i < n; i++) {
		if(!(mask & (1 << i))) {
			ret = min(ret, len[idx[p]] - junction[p][i] + solve(i, n, mask | (1 << i)));
		}
	}
	return ret;
}

void print(int p, int n, int mask) {
	if(mask == (1<<n) - 1) {
		printf("%s", str[idx[p]]);
		return;
	}
	int ret = INF, i, j, best;
	char *ptr = NULL, b;
	for(i = best = 0; i < n; i++) {
		if(!(mask & (1 << i))) {
			j = dp[i][mask | (1 << i)] + len[idx[p]] - junction[p][i];
			if(ret > j || (ret == j && strcmp(&str[idx[i]][junction[p][i]], ptr) < 0)) {
				ret = j; best = i;
				ptr = &str[idx[i]][junction[p][i]];
			}
		}
	}
	b = str[idx[p]][len[idx[p]] - junction[p][best]];
	str[idx[p]][len[idx[p]] - junction[p][best]] = 0;
	printf("%s", str[idx[p]]);
	str[idx[p]][len[idx[p]] - junction[p][best]] = b;
	print(best, n, mask | (1 << best));
}

int main() {
	int test, cs, n, i, j, ret, tmp, retid;
	//freopen("d.in", "r", stdin);
	//freopen("d2.out", "w", stdout);
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		flagv = cs;
		scanf("%d", &n);
		for(i = 0; i < n; i++) {
			scanf("%s", str[i]);
			idx[i] = i; valid[i] = 1; len[i] = strlen(str[i]);
			computeOverlap(i, str[i]);
		}
		for(i = 0; i < n; i++) {
			for(j = 0; j < n; j++) {
				if(i != j && cont[i][j] != flagv && contained(i, j)) {
					valid[i] = 0;
					cont[i][j] = cont[j][i] = flagv;
				}
			}
		}
		sort(idx, idx + n, comp);
		for(i = 0; i < n && valid[idx[i]]; i++); n = i;
		for(i = 0; i < n; i++) {
			for(j = 0; j < n; j++) {
				if(i != j) junction[i][j] = calcjunc(i, j);
				else junction[i][j] = len[idx[i]];
			}
		}
		for(ret = INF, retid = i = 0; i < n; i++) {
			tmp = solve(i, n, 1 << i);
			if(tmp < ret) ret = tmp, retid = i;
		}
		printf("Case %d: ", cs);
		print(retid, n, 1 << retid);
		printf("\n");
	}
	return 0;
}