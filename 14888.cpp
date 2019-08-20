#include <iostream>
#include <vector>
#include <algorithm>
#define PLUS 0
#define MINUS 1
#define MULTIPLY 2
#define DIVIDE 3

using namespace std;

int main() {
	int N;
	cin >> N; // 2 <= N <= 11

	int num[N];
	for(int i = 0; i < N; i++)
		cin >> num[i]; // 1 <= num <= 100

	int oper[4];
	for(int i = 0; i < 4; i++)
		cin >> oper[i]; // [0] +, [1] -, [2] *, [3] /

	/* 
	최댓값과 최솟값이 항상 -10억보다 크거나 같고, 10억보다 작거나 같다 
	일단 int형으로 표현 가능
	*/

	vector<int> opOrder;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < oper[i]; j++) {
			opOrder.push_back(i);
		}
	}

	/* print opOrder
	for(int i = 0; i < N-1; i++) {
		cout << opOrder[i];
	}
	cout << '\n'; */

	int sum;
	int max = -1000000000;
	int min = 1000000000;
	do {
		sum = num[0];
		for(int i = 0; i < N-1; i++) {
			switch(opOrder.at(i)) {
				case PLUS:
					sum += num[i+1];
					break;
				case MINUS:
					sum -= num[i+1];
					break;
				case MULTIPLY:
					sum *= num[i+1];
					break;
				case DIVIDE:
					sum /= num[i+1];
					break;
			}
		}
		if(sum > max)
			max = sum;
		if(sum < min)
			min = sum;
	} while(next_permutation(opOrder.begin(), opOrder.end()));

	cout << max << '\n';
	cout << min << '\n';
	return 0;
}