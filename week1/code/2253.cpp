#include <stdio.h>
using namespace std;
int n, x[205], y[205];
int main() {
	freopen("2253.in", "r", stdin);
	while (scanf("%d", &n) != EOF) {
		if (n == 0) return 0;
		for (int i = 0; i < n; i ++) {
			scanf("%d%d", &x[i], &y[i]);
		}
	}
}
