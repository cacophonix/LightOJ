#include <cstdio>

const int MAX = 500000000, MIN = 5;

inline int zeros(int n) {
	int ret = 0;
	while(n > 0) {
		n /= 5;
		ret += n;
	}
	return ret;
}

inline int lowerbound(int first, int last, int value) {
	int it, cnt = last - first, stp;
	while(cnt>0) {
		stp = cnt >> 1; it = first + stp;
		if(zeros(it) < value) first=++it, cnt-=stp+1;
		else cnt=stp;
	}
	return first;
}

int main() {
	int n, test, cs, p;
	scanf("%d", &cs);
	for(test = 1; test <= cs; test++) {
		scanf("%d", &n);
		p = lowerbound(MIN, MAX, n);
		if(zeros(p) == n) printf("Case %d: %d\n", test, p);
		else printf("Case %d: impossible\n", test);
	}
	return 0;
}
