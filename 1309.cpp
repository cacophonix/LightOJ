#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

typedef struct { int a, b; char oper; } Type; // ax+b

inline bool isoper(char ch) {
	return (ch=='+' || ch=='-' || ch =='*');
}

inline int prior(char ch) {
	if(ch == '*') return 3;
	return 2;
}

inline Type add(const Type &x, const Type &y) {
	return (Type){x.a+y.a, x.b+y.b, 0};
}

inline Type sub(const Type &x, const Type &y) {
	return (Type){x.a-y.a, x.b-y.b, 0};
}

inline Type mul(const Type &x, const Type &y) {
	if(!x.a) return (Type){y.a*x.b, y.b*x.b, 0};
	return (Type){x.a*y.b, x.b*y.b, 0};
}

Type getVal(char *expr) {
	int i, j, n;
	Type tmp, ta, tb, tc;
	stack < char > S;
	stack < Type > E;
	vector< Type > V;
	for(i = 0; expr[i]; i++) {
		if(expr[i] == '(') S.push('(');
		else if(expr[i] == ')') {
			while(!S.empty() && S.top() != '(') {
				tmp = (Type){0, 0, S.top()};
				V.push_back(tmp);
				S.pop();
			}
			if(!S.empty()) S.pop();
		}
		else if(isoper(expr[i])) {
			while(!S.empty() && isoper(S.top()) && prior(S.top()) >= prior(expr[i])) {
				tmp = (Type){0, 0, S.top()};
				V.push_back(tmp);
				S.pop();
			}
			S.push(expr[i]);
		}
		else if(expr[i]=='x') {
			tmp = (Type){1, 0, 0};
			V.push_back(tmp);
		}
		else {
			for(n = 0, j = i; expr[j] && isdigit(expr[j]); j++) {
				n = n * 10 + expr[j] - 48;
			}
			tmp = (Type){0, n, 0};
			V.push_back(tmp);
			i = j-1;
		}
	}
	while(!S.empty()) {
		tmp = (Type){0, 0, S.top()};
		V.push_back(tmp);
		S.pop();
	}
	n = V.size();
	for(i = 0; i < n; i++) {
		if(V[i].oper) {
			tb = E.top(); E.pop();
			ta = E.top(); E.pop();
			switch(V[i].oper) {
				case '+': tc = add(ta, tb); E.push(tc); break;
				case '-': tc = sub(ta, tb); E.push(tc); break;
				case '*': tc = mul(ta, tb); E.push(tc); break;
			}
		}
		else E.push(V[i]);
	}
	return E.top();
}

int gcd(int a, int b) {
	if(!b) return a;
	return gcd(b, a % b);
}

int main() {
	int test, cs, a, b, g;
	char expr1[128], *expr2;
	Type lhs, rhs, tmp;
	//freopen("in.txt", "r", stdin);
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%s", expr1);
		expr2 = strchr(expr1, '='); *expr2++ = 0;
		lhs = getVal(expr1);
		rhs = getVal(expr2);
		tmp = sub(lhs, rhs);
		printf("Case %d: ", cs);
		if(tmp.a == 0 && tmp.b == 0) printf("infinitely many solutions\n");
		else if(tmp.a == 0 && tmp.b != 0) printf("no solution\n");
		else {
			a = tmp.a, b = -tmp.b;
			g = gcd(abs(a), abs(b));
			a /= g, b /= g;
			if(a < 0) a *= -1, b *= -1;
			if(a == 1) printf("%d\n", b);
			else printf("%d/%d\n", b, a);
		}
	}
	return 0;
}
