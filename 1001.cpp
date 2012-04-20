#include<stdio.h>

int main() {
    int n, t, a, b;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        a = n > 10? 10 : n;
        b = n - a;
        printf("%d %d\n", a, b);
    }
    return 0;
}
