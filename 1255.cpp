#include <cstdio>

char *pattern, *str, *ptr;
int overlap[0x100000];
char buff[0x800000];

#define nextint(x) while(*ptr<48)ptr++;for(x=0;*ptr>47;x=x*10+*ptr++-48);
#define nextstr(x,l) while(*ptr<33)ptr++;x=ptr;while(*ptr>32)ptr++;l=ptr-x;*ptr=0;

void computeOverlap(int len) {
	overlap[0] = -1;
	for(int i = 0; i < len; i++) {
		overlap[i+1] = overlap[i] + 1;
		while(overlap[i+1] > 0 && pattern[i] != pattern[overlap[i+1]-1]) {
			overlap[i+1] = overlap[overlap[i+1]-1] + 1;
		}
	}
}

int kmpMatcher(int plen, int slen) {
	int i, j, ret;
	for(i = j = ret = 0; i < slen; i++) {
		while(true) {
			if(str[i] == pattern[j]) {
				j++;
				if(j == plen) {
					ret++;
					j = overlap[j];
				}
				break;
			}
			else if(!j) break;
			else j = overlap[j];
		}
	}
	return ret;
}

int main() {
	int test, cs, slen, plen;
	//freopen("in.txt", "r", stdin);
	fread_unlocked(buff, 1, 0x800000, stdin); ptr = buff;
	nextint(test);
	for(cs = 1; cs <= test; cs++) {
		nextstr(str,slen);
		nextstr(pattern,plen);
		if(plen > slen) {
			printf("Case %d: 0\n", cs);
			continue;
		}
		computeOverlap(plen);
		printf("Case %d: %d\n", cs, kmpMatcher(plen, slen));
	}
	return 0;
}
