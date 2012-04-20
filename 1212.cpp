#include <cstdio>
using namespace std;

int maxsz, cursz, front, back, que[16];
char buff[32];

inline void pushFront(int v) {
	if(!cursz) {
		que[0] = v;
		front = back = 0;
	}
	else {
		front--;
		if(front < 0) front = maxsz - 1;
		que[front] = v;
	}
	cursz++;
}

inline void pushBack(int v) {
	if(!cursz) {
		que[0] = v;
		front = back = 0;
	}
	else {
		back++;
		if(back == maxsz) back = 0;
		que[back] = v;
	}
	cursz++;
}

inline int popFront() {
	int v = que[front];
	front++;
	if(front == maxsz) front = 0;
	cursz--;
	return v;
}

inline int popBack() {
	int v = que[back];
	back--;
	if(back < 0) back = maxsz - 1;
	cursz--;
	return v;
}

int main() {
	int test, cs, q, temp;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		fprintf(stdout, "Case %d:\n", cs);
		scanf("%d %d", &maxsz, &q);
		cursz = 0;
		while(q--) {
			scanf("%s", buff);
			if(buff[4]=='L') {
				scanf("%d", &temp);
				if(1 > maxsz - cursz) fputs("The queue is full\n", stdout);
				else {
					pushFront(temp);
					fprintf(stdout, "Pushed in left: %d\n", temp);
				}
			}
			else if(buff[4]=='R') {
				scanf("%d", &temp);
				if(1 > maxsz - cursz) fputs("The queue is full\n", stdout);
				else {
					pushBack(temp);
					fprintf(stdout, "Pushed in right: %d\n", temp);
				}
			}
			else if(buff[3]=='L') {
				if(1 > cursz) fputs("The queue is empty\n", stdout);
				else fprintf(stdout, "Popped from left: %d\n", popFront());
			}
			else if(buff[3]=='R') {
				if(1 > cursz) fputs("The queue is empty\n", stdout);
				else fprintf(stdout, "Popped from right: %d\n", popBack());
			}
		}
	}
	return 0;
}
