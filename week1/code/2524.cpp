#include <stdio.h>
using namespace std;
int n, m, a, b, fa[50002];
void init(int n) {
	for (int i = 0; i <= n; i ++) {
		fa[i] = i;
	}
}
int find(int x){//带路压
     if(fa[x]!=x)//不是最终父亲，即父亲是自己的元素
         fa[x]=find(fa[x]);//递归更新，路径压缩。。。这里特别复杂，建议没有学过的人好好理解
     return fa[x];
}
void unionn(int x,int y){//合并函数，带路压
     int r1=find(x),r2=find(y);//找到xy的父亲，把其中一个父亲的父亲设置为另一个的父亲。
     fa[r2]=r1;

    find(y);//路径压缩，把y的每个父亲及其父亲的父亲设置为改变后的父亲。
}
int main() {
	//freopen("2524.in", "r", stdin);
	int cs = 1;
	while (1) {
		scanf("%d%d", &n, &m);
		if (m == 0 && n == 0) return 0;
		init(n);
		for (int i = 0; i < m; i ++) {
			scanf("%d%d", &a, &b);
			unionn(a, b);
		}
		int c= 0;
		for (int i = 1; i <= n; i ++) {
			if (fa[i] == i) c++;
		}
		printf("Case %d: %d\n", cs++, c);
	}
} 
