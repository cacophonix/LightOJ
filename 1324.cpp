#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

int mp[10], n;

inline int pre(char ch) {
	switch(ch) {
		case '!': return 3;
		case '&': return 2;
		case '|': return 1;
	}
	return 0;
}

void getPostfix(char *expr, char *postfix) {
	int i, j, k;
	stack< char > S;
	for(i = k = 0; expr[i]; i++) {
		if(expr[i] == '!') S.push('!');
		else if(expr[i] == '(') S.push('(');
		else if(expr[i] == ')') {
			while(!S.empty() && S.top() != '(') {
				postfix[k++] = S.top();
				S.pop();
			}
			S.pop();
			if(!S.empty() && S.top() == '!') {
				postfix[k++] = S.top();
				S.pop();
			}
		}
		else if('a' <= expr[i] && expr[i] <= 'j') {
			if(mp[expr[i] - 'a'] == -1) mp[expr[i] - 'a'] = n++;
			postfix[k++] = expr[i];
			if(!S.empty() && S.top() == '!') {
				postfix[k++] = S.top();
				S.pop();
			}
		}
		else {
			while(!S.empty() && pre(S.top()) >= pre(expr[i])) {
				postfix[k++] = S.top();
				S.pop();
			}
			S.push(expr[i]);
		}
	}
	while(!S.empty()) {
		postfix[k++] = S.top();
		S.pop();
	}
	postfix[k] = 0;
}

bool eval(char *postfix, int pat) {
	stack< bool > S;
	bool a, b;
	int i;
	for(i = 0; postfix[i]; i++) {
		if(postfix[i] == '!') S.top() = S.top() ^ 1;
		else if(postfix[i] == '|' || postfix[i] == '&') {
			b = S.top(); S.pop();
			a = S.top(); S.pop();
			if(postfix[i] == '|') S.push(a | b);
			else S.push(a & b);
		}
		else S.push((pat >> mp[postfix[i] - 'a']) & 1);
	}
	return S.top();
}

int main() {
	char expr1[128], expr2[128];
	char post1[128], post2[128];
	int test, cs, i;
	//freopen("in.txt", "r", stdin);
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%s %s", expr1, expr2);
		n = 0;
		memset(mp, -1, sizeof mp);
		getPostfix(expr1, post1);
		getPostfix(expr2, post2);
		for(i = 0; i < (1 << n); i++) {
			if(eval(post1, i) != eval(post2, i)) break;
		}
		if(i == (1 << n)) printf("Case %d: Equivalent\n", cs);
		else printf("Case %d: Not Equivalent\n", cs);
	}
	return 0;
}