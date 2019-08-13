#include <iostream>
using namespace std;

bool isPrime(int num) {
	if(num == 1)
		return false;
	
	for(int i = 2; i*i <= num; i++) {
		if(num % i == 0)
			return false;
	}
	return true;
}

int main() {
	int n; // n <= 100
	cin >> n;
	int arr[n];
	int primeCnt = 0;

	for(int i = 0; i < n; i++) {
		cin >> arr[i];
		if(isPrime(arr[i]))
			primeCnt++;
	}

	cout << primeCnt << endl;
	return 0;
}