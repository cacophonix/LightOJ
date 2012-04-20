#include <cstdio>
using namespace std;

#define i64 long long
#define MOD(n,m) (n<m?n:n%m)

inline bool div(char *num, int n) {
	i64 mod = 0;
	for(int i = 0; num[i]; i++) mod = MOD((mod * 10 + (num[i]&0x0f)), n);
	return (mod!=0);
}

int main() {
	int test, cs = 1, n;
	char str[256];
	scanf("%d", &test);
	while(test--) {
		scanf("%s %d", str, &n);
		n = div(str + (*str=='-'? 1 : 0), (n<0? -n : n));
		printf("Case %d: %s\n", cs++, (n? "not divisible" : "divisible"));
	}
	return 0;
}
