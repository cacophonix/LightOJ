#include <cstdio>
#include <cstring>

int g[201];

int grundy(int n) {
	if(n <= 0) return 0;
	if(g[n] != -1) return g[n];
	int i, ret, p = n >> 1, t[201];
	for(i = 0; i <= p; i++) t[grundy(i-2) ^ grundy(n-3-i)] = n;
	for(i = ret = 0; i <= n && t[ret]==n; i++, ret++);
	return g[n] = ret;
}

int main() {
	int test, cs, n, i, xsum, nb, tmp, g1, g2, next;
	int xcntf[256], xcntb[256], dcntb[256], dcntf[256], idx[256], buff[256];
	char board[256];
	memset(g, -1, sizeof g);
	g[0] = xcntf[0] = dcntf[0] = xcntb[0] = dcntb[0] = 0;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%s", board);
		n = strlen(board);
		printf("Case %d:", cs);
		for(i = 1; i <= n; i++) {
			if(board[i-1]=='X') xcntf[i] = 1 + xcntf[i-1], dcntf[i] = 0;
			if(board[i-1]=='.') xcntf[i] = 0, dcntf[i] = 1 + dcntf[i-1];
		}
		xcntf[i] = xcntb[i] = dcntf[i] = dcntb[i] = 0;
		for(i = n; i >= 1; i--) {
			if(board[i-1]=='X') xcntb[i] = 1 + xcntb[i+1], dcntb[i] = 0;
			if(board[i-1]=='.') xcntb[i] = 0, dcntb[i] = 1 + dcntb[i+1];
		}
		for(nb = 0, i = 1; i <= n; i++) {
			if(board[i-1]=='X') continue;
			if(xcntf[i-1]>1 || xcntb[i+1]>1) buff[nb++] = i;
			else if(xcntf[i-1]==1 && xcntb[i+1]==1) buff[nb++] = i;
		}
		if(nb > 0) {
			for(i = 0; i < nb; i++) printf(" %d", buff[i]); printf("\n");
			continue;
		}
		for(nb = 0, i = 1; i <= n; i++) {
			if(board[i-1] == 'X') {
				if(i > 1) buff[nb++] -= 4;
			}
			else {
				buff[nb] = dcntf[i];
				idx[i] = nb;
			}
		}
		if(board[n-1] != 'X') buff[nb++] -= 4;
		if(board[0] != 'X') buff[0] += 2;
		if(board[n-1] != 'X') buff[nb-1] += 2;
		for(i = xsum = 0; i < nb; i++) xsum ^= grundy(buff[i]);
		if(!xsum) printf(" 0\n");
		else {
			for(i = 1; i <= n; i++) {
				if(board[i-1] == 'X') continue;
				if(i >= 2 && board[i-2] == 'X') continue;
				if(i >= 3 && board[i-3] == 'X') continue;
				if(i < n && board[i] == 'X') continue;
				if(i + 1 < n && board[i+1] == 'X') continue;
				if(idx[i]==0 && board[0]!='X') g1 = dcntf[i] - 3;
				else g1 = dcntf[i] - 5;
				if(idx[i]==nb-1 && board[n-1]!='X') g2 = dcntb[i]-3;
				else g2 = dcntb[i] - 5;
				tmp = xsum ^ grundy(buff[idx[i]]);
				tmp ^= grundy(g1);
				tmp ^= grundy(g2);
				if(!tmp) printf(" %d", i);
			}
			printf("\n");
		}
	}
	return 0;
}
