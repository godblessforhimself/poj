#include <stdio.h> 
#include <queue>
#include <string.h>
using namespace std;
#define MAXN 100000
int N, K, searched[MAXN + 1];
struct step {
	int pos;
	int steps;
	step(int p, int s): pos(p), steps(s) {searched[p] = 1;}
};
queue<step> q;
int main(int argc, char const *argv[])
{
	/* code */
	memset(searched, 0, sizeof(searched));
	scanf("%d%d", &N, &K);
	q.push(step(N, 0));
	while (!q.empty()) {
		step c = q.front();
		if (c.pos != K) {
			int dou = (c.pos << 1), left = c.pos - 1, right = c.pos + 1;
			if (dou <= 100000 && !searched[dou])
			q.push(step(c.pos << 1, c.steps + 1));
			if (right <= 100000 && !searched[right])
			q.push(step(c.pos + 1, c.steps + 1));
			if (left >= 0 && !searched[left])
			q.push(step(c.pos - 1, c.steps + 1));
			q.pop();
		} else {
			printf("%d\n", c.steps);
			return 0; 
		}
	}
	return 0;
}
