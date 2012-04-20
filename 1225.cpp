#include <cstdio>

inline int rev(int n) {
	int ret = 0;
	while(n > 0) {
		ret = ret * 10 + n % 10;
		n /= 10;
	}
	return ret;
}

int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	int test, cs = 1, n;
	scanf("%d", &test);
	while(test--) {
		scanf("%d", &n);
		if(n == rev(n)) printf("Case %d: Yes\n", cs++);
		else printf("Case %d: No\n", cs++);
	}
	return 0;
}
