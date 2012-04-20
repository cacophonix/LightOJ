#include <cstdio>
#include <cstring>
#include <list>
using namespace std;

int main() {
	int test, cs, n, m, tm, i, j;
	int men[20], seat[20], curr[20];
	list < int > L;
	list < int > :: iterator it;
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		tm = 0;
		L.clear();
		memset(men, 0, sizeof men);
		memset(seat, 0, sizeof seat);
		memset(curr, -1, sizeof curr);
		scanf("%d %d", &n, &m);
		for(i = 0; i < n; i++) L.push_back(i);
		i = 0;
		while(true) {
			tm += 5;
			//printf("Time: %d, Bottom: %d,", tm, i + 1);
			for(j = 0, it = L.begin(); it != L.end(); it++, j++) {
				if(!(seat[i] & (1 << *it))) break;
			}
			if(it != L.end()) {
				if(curr[i] != -1) {
					seat[i] |= (1 << curr[i]);
					men[curr[i]] |= (1 << i);
					if(men[curr[i]] != (1 << m) - 1) L.push_back(curr[i]);
					//printf(" Exit: %d,", curr[i] + 1);
				}
				curr[i] = *it;
				L.erase(it);
				//printf(" Enter: %d,", curr[i] + 1);
			}
			else {
				if(curr[i] != -1) {
					seat[i] |= (1 << curr[i]);
					men[curr[i]] |= (1 << i);
					if(men[curr[i]] != (1 << m) - 1) L.push_back(curr[i]);
					//printf(" Exit: %d,", curr[i] + 1);
					curr[i] = -1;
				}
			}
			//printf("\n");
			for(j = 0; j < n; j++) if(men[j] != (1 << m) - 1) break;
			if(j == n) break;
			i++; if(i >= m) i = 0;
		}
		printf("Case %d: %d\n", cs, tm);
	}
	return 0;
}