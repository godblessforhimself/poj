#include <stdio.h>
using namespace std;
int n, m, a, b, fa[50002];
void init(int n) {
	for (int i = 0; i <= n; i ++) {
		fa[i] = i;
	}
}
int find(int x){//��·ѹ
     if(fa[x]!=x)//�������ո��ף����������Լ���Ԫ��
         fa[x]=find(fa[x]);//�ݹ���£�·��ѹ�������������ر��ӣ�����û��ѧ�����˺ú����
     return fa[x];
}
void unionn(int x,int y){//�ϲ���������·ѹ
     int r1=find(x),r2=find(y);//�ҵ�xy�ĸ��ף�������һ�����׵ĸ�������Ϊ��һ���ĸ��ס�
     fa[r2]=r1;

    find(y);//·��ѹ������y��ÿ�����׼��丸�׵ĸ�������Ϊ�ı��ĸ��ס�
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
