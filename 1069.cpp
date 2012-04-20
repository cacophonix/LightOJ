#include <cstdio>
using namespace std;

int main() {
	int me, lift, test, cs = 1;
	scanf("%d", &test);
	while(test--) {
		scanf("%d %d", &me, &lift);
		if(lift < me) lift = (me << 1) - lift;
		printf("Case %d: %d\n", cs++, (lift<<2) + 19);
	}
	return 0;
}
