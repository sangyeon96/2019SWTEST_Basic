#include <iostream>
#include <queue>
using namespace std;

/* 인접 행렬 */
void bfs() {
	queue<int> q;
	check[1] = true;
	q.push(1);
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		printf("%d ", x);
		for(int i = 1; i <= n; i++) {
			if(a[x][i] == 1 && check[i] == false) {
				check[i] = true;
				q.push(i);
			}
		}
	}
}

/* 인접 리스트 */
void bfs() {
	queue<int> q;
	check[1] = true;
	q.push(1);
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		printf("%d", x);
		for(int i = 0; i < a[x].size; i++) {
			int y = a[x][i];
			if(check[y] == false) {
				check[y] = true;
				q.push(y);
			}
		}
	}
}

int main() {
	return 0;
}