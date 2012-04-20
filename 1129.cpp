#include <cstdio>
#include <cstring>
using namespace std;

const int MAX = 10000;
const int BUFF = 0x200000;

static char *phn[MAX], *sq[10][MAX], buff[BUFF], *ptr;
static int len[MAX], lq[10][MAX], top[10];

#define nextint(x) while(*ptr<48)ptr++;for(x=0;*ptr>47;x=x*10+*ptr++-48)
#define nextstr(x,l) while(*ptr<33)ptr++;x=ptr;while(*ptr>32)ptr++;l=ptr-x;*ptr++=0

int main() {
	int test, cs, n, i, j, k, idx, mxlen;
	fread_unlocked(buff, 1, BUFF, stdin);
	ptr = buff;
	nextint(test);
	for(cs = 1; cs <= test; cs++) {
		nextint(n);
		for(i = mxlen = 0; i < n; i++) {
			nextstr(phn[i], len[i]);
			if(mxlen < len[i]) mxlen = len[i];
		}
		for(i = mxlen-1; i >= 0; i--) {
			for(j = 0; j < n; j++) {
				k = i < len[j]? phn[j][i]-48 : 0;
				sq[k][top[k]] = phn[j];
				lq[k][top[k]] = len[j];
				top[k]++;
			}
			for(k = idx = 0; k < 10; k++) {
				for(j = 0; j < top[k]; j++) {
					phn[idx] = sq[k][j];
					len[idx] = lq[k][j];
					idx++;
				}
				top[k] = 0;
			}
		}
		for(i = 1; i < n; i++) {
			if(!strncmp(phn[i-1], phn[i], len[i-1])) {
				break;
			}
		}
		if(i == n) printf("Case %d: YES\n", cs);
		else printf("Case %d: NO\n", cs);
	}
	return 0;
}
