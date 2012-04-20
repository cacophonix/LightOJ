#include <cstdio>

int main(){
       int test, cs, n, i, a[128];
       scanf("%d", &test);
       for(cs = 1; cs <= test; cs++) {
               scanf("%d", &n);
               int cnt = 0;
               for(i=0; i<n; i++){
                       scanf("%d", &a[i]);
                       if(a[i]==1) cnt++;
               }
               if(cnt==n){
                       if(n & 1) printf("Case %d: Bob\n", cs);
                       else printf("Case %d: Alice\n", cs);
               }
               else {
                       for(i=1; i<n; i++)a[0]^=a[i];
                       if(a[0]==0) printf("Case %d: Bob\n", cs);
                       else printf("Case %d: Alice\n", cs);
               }
       }
       return 0;
}

/*
#include <cstdio>
#include <algorithm>
using namespace std;

pair< int, int > turn(int *heaps, int n) {
	int x, i, p, remove, twomore, temp, sum;
	bool sums[n];
	for(i = x = 0; i < n; i++) x ^= heaps[i];
	if(!x) {
		for(i = 0; i < n; i++)
			if(heaps[i] > 0)
				break;
		return pair< int, int >(i, heaps[i]);
	}
	else {
		for(i = 0; i < n; i++) sums[i] = (heaps[i] ^ x) < heaps[i];
		p = find(sums, sums+n, true) - sums;
		remove = heaps[p] - (heaps[p] ^ x);
		twomore = 0;
		for(i = 0; i < n; i++) {
			temp = (p==i)? heaps[i] - remove : heaps[i];
			if(temp > 1) twomore += 1;
		}
		if(!twomore) {
			p = find(heaps, heaps+n, *max_element(heaps, heaps + n)) - heaps;
			sum = 0;
			for(i = 0; i < n; i++)
				if(heaps[i]==1)
					sum++;
			remove = (sum&1)? heaps[p] : heaps[p] - 1;
		}
		return pair< int, int >(p, remove);
	}
}

int main() {
	int n, heaps[50], i, t, pl;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(i=0; i<n; i++) scanf("%d", &heaps[i]);
		// john 1, Bro 0
		pl = 1; // init john
		while(1) {
			pair< int, int > pii = turn(heaps, n);
			if(pii.first == n) break;
			heaps[pii.first] -= pii.second;
			pl ^= 1; // alter
		}
		// now pl could not make his turn, so pl wins
		if(pl) printf("John\n");
		else printf("Brother\n");
	}
	return 0;
}
*/
