#include <iostream>
using namespace std;

int gcd(int a, int b) {
	int r;

	while(b != 0) {
		r = a % b;
		a = b;
		b = r;
	}

	return a;
}

int main() {
	int testCnt; // 1 <= t <= 100
	int i, j, k;

	cin >> testCnt;
	for(i = 0; i < testCnt; i++) {
		int n;
		cin >> n; // 1 < n <= 100

		int arr[n];
		for(j = 0; j < n; j++) {
			cin >> arr[j];
		}

		long long sum; /* 자료형 주의! */
		if(n == 1)
			sum = arr[0];
		else {
			sum = 0;
			for(j = 0; j < n-1; j++) {
				for(k = j+1; k < n; k++) {
					sum += gcd(arr[j], arr[k]);
				}
			}
		}
		cout << sum << endl;
	}

	return 0;
}