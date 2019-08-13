#include <iostream>
using namespace std;

int gcd(int a, int b) { //최대공약수
	int r;

	while(b != 0) { //유클리드호제법
		r = a % b;
		a = b;
		b = r;
	}
	
	return a;
}

int lcm(int a, int b) { //최소공배수
	return a * b / gcd(a, b);
}

int main() {
	int a, b;
	cin >> a >> b;

	cout << gcd(a, b) << endl;
	cout << lcm(a, b) << endl;

	return 0;
}