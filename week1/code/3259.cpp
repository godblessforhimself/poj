#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAXN 10005
int F, N, M, W, u[10000], v[10000], t[10000], dist[MAXN];
#define INF (0x3f3f3f3f)
int main() {
	//freopen("3259.in", "r", stdin);
	scanf("%d", &F);
	for (int i = 0; i < F; i++) {
		scanf("%d%d%d", &N, &M, &W);
		for (int i = 0; i < M; i ++) {
			scanf("%d%d%d", &u[i], &v[i], &t[i]);
		}
		for (int i = 0; i < W; i ++) {
			scanf("%d%d%d", &u[i + M], &v[i + M], &t[i + M]);
			t[i + M] = -t[i + M];
		}
		for (int i = 1; i <= N; i ++) {
			dist[i] = INF;
		}
		dist[1] = 0;
		for (int k = 1; k < N; k ++) {
			for (int i = 0; i < M; i ++) {
				//[u,v] & [v,u]
				int a = u[i], b = v[i];
				if (dist[b] > dist[a] + t[i])
				dist[b] = dist[a] + t[i];
				if (dist[a] > dist[b] + t[i])
				dist[a] = dist[b] + t[i];
			}
			for (int i = 0; i < W; i++) {
				int a = u[i], b = v[i];
				if (dist[b] > dist[a] + t[i])
				dist[b] = dist[a] + t[i];
			}
		}
		for (int i = 0; i < M + W; i ++) {
			if (i < M) {
				int a = u[i], b = v[i];
				if (dist[a] > dist[b] + t[i] || dist[b] > dist[a] + t[i])
					goto minus;
			} else {
				int a = u[i], b = v[i];
				if (dist[b] > dist[a] + t[i])
					goto minus;
			}
		}
		printf("NO\n");
		continue;
		minus:
		printf("YES\n");
	}
	
}
