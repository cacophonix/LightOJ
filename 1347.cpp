#include <cstdio>
#include <cstring>

const int MAX = 1 << 14;

char str[MAX], dummy[2];
int c[MAX], s[MAX];
int height[MAX], SA[MAX];
int range[16][2], nstr, len;

inline bool leq(int a1, int a2, int b1, int b2) {
	return(a1 < b1 || (a1 == b1 && a2 <= b2));
}

inline bool leq(int a1, int a2, int a3, int b1, int b2, int b3) {
	return(a1 < b1 || (a1 == b1 && leq(a2,a3, b2,b3)));
}

static void radixPass(int* a, int* b, int* r, int n, int K) {
	int i, sum, t;
	for(i = 0;  i <= K;  i++) c[i] = 0;
	for(i = 0;  i < n;  i++) c[r[a[i]]]++;
	for(i = 0, sum = 0;  i <= K;  i++) {
		t = c[i];
		c[i] = sum;
		sum += t;
	}
	for(i = 0;  i < n;  i++) b[c[r[a[i]]]++] = a[i];
}
 
void suffixArray(int* s, int* SA, int n, int K) {
	int n0 = (n+2)/3, n1 = (n+1)/3, n2 = n/3, n02 = n0+n2;
	int* s12 = new int[n02 + 3];
	int* SA12 = new int[n02 + 3];
	int* s0 = new int[n0];
	int* SA0 = new int[n0];
	int i, j, name, c0, c1, c2, p, t, k;
	s12[n02] = s12[n02+1] = s12[n02+2] = 0;
	SA12[n02] = SA12[n02+1] = SA12[n02+2] = 0;
	for(i=0, j=0; i < n+(n0-n1); i++) if(i%3 != 0) s12[j++] = i;
	radixPass(s12, SA12, s+2, n02, K);
	radixPass(SA12, s12, s+1, n02, K);
	radixPass(s12, SA12, s, n02, K);
	name = 0, c0 = -1, c1 = -1, c2 = -1;
	for(i = 0; i < n02; i++) {
		if(s[SA12[i]] != c0 || s[SA12[i]+1] != c1 || s[SA12[i]+2] != c2) {
			name++;
			c0 = s[SA12[i]];
			c1 = s[SA12[i]+1];
			c2 = s[SA12[i]+2];
		}
		if(SA12[i] % 3 == 1) s12[SA12[i]/3] = name;
		else s12[SA12[i]/3 + n0] = name;
	}
	if(name < n02) {
		suffixArray(s12, SA12, n02, name);
		for(i = 0; i < n02; i++) s12[SA12[i]] = i + 1;
	}
	else for(i = 0; i < n02; i++) SA12[s12[i] - 1] = i;
	for(i=0, j=0; i < n02; i++) if(SA12[i] < n0) s0[j++] = 3*SA12[i];
	radixPass(s0, SA0, s, n0, K);
	#define GetI() (SA12[t] < n0 ? SA12[t] * 3 + 1 : (SA12[t] - n0) * 3 + 2)
	for(p=0, t=n0-n1, k=0; k < n; k++) {
		i = GetI(); j = SA0[p];
		if(SA12[t] < n0 ? leq(s[i], s12[SA12[t] + n0], s[j], s12[j/3]) : leq(s[i], s[i+1], s12[SA12[t]-n0+1], s[j], s[j+1], s12[j/3+n0])) {
			SA[k] = i; t++;
			if(t == n02) for(k++; p < n0; p++, k++) SA[k] = SA0[p];
		}
		else {
			SA[k] = j; p++;
			if(p == n0) for(k++; t < n02; t++, k++) SA[k] = GetI();
		}
	}
	delete[] s12; delete[] SA12; delete[] SA0; delete[] s0;
}

void Suffix_Array(int n){
	int m, i;
	for(i = 0, m = -1; i < n; i++) {
		s[i] = str[i];
		m = m > str[i]? m : str[i];
	}
	for(i = n; i < n + 3; i++) s[i] = SA[i] = 0;
	suffixArray(s, SA, n, m);
}
 
void getHeight(int n) {
	int h, i, j;
	for(i=0; i<n; i++) s[SA[i]] = i;
	height[0] = 0;
	for(i=0, h=0; i<n; i++){
		if(s[i] > 0){
			j = SA[s[i]-1];
			while(i + h < n && j + h < n && str[i+h] == str[j+h]) h++;
			height[s[i]] = h;
			if(h > 0) h--;
		}
	}
}

void input() {
	gets(dummy);
	range[0][0] = len = 0;
	for(int i = 0; i < 3; i++) {
		gets(&str[range[len][0]]);
		range[len+1][0] = range[len][1] = range[len][0] + strlen(&str[range[len][0]]);
		len++;
	}
	nstr = len; len = range[len][0];
}

int findstr(int idx) {
	for(int i = 0; i < nstr; i++)
		if(range[i][1] > idx)
			return i;
	return -1;
}

int main() {
	int i, j, ans, p, thislcp, test, cs;
	bool flag[11];
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	scanf("%d", &test);
	gets(dummy);
	for(cs = 1; cs <= test; cs++) {
		input();
		Suffix_Array(len);
		getHeight(len);
		ans = 0;
		for(i = 0; i + nstr <= len; i++) {
			for(j = 0; j < nstr; j++) flag[j] = false;
			thislcp = 1<<30;
			for(j = i; j < i + nstr; j++) {
				p = findstr(SA[j]);
				if(flag[p]) break;
				flag[p] = true;
				if(j > i) thislcp = height[j] < thislcp ? height[j] : thislcp;
			}
			if(j == i + nstr) ans = ans > thislcp ? ans : thislcp;
		}
		printf("Case %d: %d\n", cs, ans);
	}
	return 0;
}