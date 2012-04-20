#include <cstdio>
#include <cstring>

char str[51];
int dp[50][4][6];

inline bool isvowel(char ch) {
	return ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
}

int solve(int i, int vwls, int cons) {
	if(vwls == 3 || cons == 5) return 1;
	if(!str[i]) return 2;
	if(dp[i][vwls][cons] != -1) return dp[i][vwls][cons];
	if(str[i] == '?')
		dp[i][vwls][cons] = solve(i + 1, vwls + 1, 0) | solve(i + 1, 0, cons + 1);
	else if(isvowel(str[i]))
		dp[i][vwls][cons] = solve(i + 1, vwls + 1, 0);
	else
		dp[i][vwls][cons] = solve(i + 1, 0, cons + 1);
	return dp[i][vwls][cons];
}

int main() {
	int test, cs, ret;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%s", str);
		memset(dp, -1, sizeof(dp));
		ret = solve(0, 0, 0);
		if(ret == 1) printf("Case %d: BAD\n", cs);
		else if(ret == 2) printf("Case %d: GOOD\n", cs);
		else printf("Case %d: MIXED\n", cs);
	}
	return 0;
}