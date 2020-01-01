#include <iostream>
using namespace std;

/* 인접 행렬 */
void dfs(int x) {
	check[x] = true; // x 정점 방문 체크
	printf("%d ", x);
	for(int i = 1; i <= n; i++) {
		if(a[x][i] == 1 && check[i] == false) {
			dfs(i);
		}
	}
}

/* 인접 리스트 */
void dfs(int x) {
	check[x] = true;
	printf("%d ", x);
	for(int i = 0; i < a[x].size; i++) {
		int y = a[x][i];
		if(check[y] == false) {
			dfs(y);
		}
	}
}

int main() {
	return 0;
}