#include <iostream>
using namespace std;

/* 
 벡터를 이용하여 2부터 시작하여 소수인 수를 벡터에 넣고, 
 그 이후로는 벡터에 있는 수와 비교하여 나누어떨어지는지 확인하였더니
 시간초과(이중for문인데 m,n은 백만까지이므로..최대 백만*백만은 2억 넘으니까..)
*/

const int MAX = 1000000;
bool isNotPrime[MAX+1];

int main() {
	int i, j;

	isNotPrime[0] = isNotPrime[1] = true;
	for(i = 2; i*i <= MAX; i++) {
		if(isNotPrime[i] == false) {
			for(j = 2; i * j <= MAX; j++) {
				isNotPrime[i*j] = true;
			}
		}
	}

	int m, n; // 1 <= m, n <= 1,000,000
	cin >> m >> n;
	for(i = m; i <= n; i++) {
		if(isNotPrime[i] == false) {
			cout << i << '\n';
			/* endl은 버퍼를 flush하기 때문에 너무 느리다..! */
		}
	}
	return 0;
}