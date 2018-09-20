#include <stdio.h>
using namespace std;
struct bigInt{
	int v[1000];
	int top;
	bigInt operator+(const bigInt& a, const bigInt& b) {
		int tmax = max(a.top, b.top);
		int arr[1000] = {0};
		for (int i = 0; i < tmax; i++) {
			int temp = a.v[i] + b.v[i];
		}
	}
};
int n;
int main() {
	freopen("2506.in", "r", stdin);
	while (scanf("%d", &n) != EOF) {
		
	}
} 
