#include <iostream>
using namespace std;

/*
예를 들어, n = 7이면,
(1, 1, 1, 1, 1, 2) = 6! / (5! * 1!)
(1, 1, 1, 2, 2) = 5! / (3! * 2!)
(1, 2, 2, 2) = 4! / (3! * 1!)
공식 이용
*/

int factorial(int n) {
	if(n == 0 || n == 1)
		return 1;
	else
		return n * factorial(n-1);
}

int main() {
	int testCnt;
	cin >> testCnt;

	for(int i = 0; i < testCnt; i++) {
		int n;
		cin >> n; // 0 <= n < 11

		int answer = 0; // n을 1,2,3의 합으로 나타내는 방법의 수
		int threeCnt, twoCnt, oneCnt;
		int tmp;
		for(threeCnt = 0; 3 * threeCnt <= n; threeCnt++) {
			for(twoCnt = 0; 2 * twoCnt <= n; twoCnt++) {
				for(oneCnt = 0; 1 * oneCnt <= n; oneCnt++) {
					if(1 * oneCnt + 2 * twoCnt + 3 * threeCnt == n) {
						//cout << "1 * " << oneCnt << " + 2 * " << twoCnt << " + 3 * " << threeCnt << " = " << n << '\n';
						tmp = factorial(oneCnt + twoCnt + threeCnt) / (factorial(oneCnt) * factorial(twoCnt) * factorial(threeCnt));
						answer += tmp;
					}
				}
			}
		}
		cout << answer << '\n';
	}

	return 0;
}