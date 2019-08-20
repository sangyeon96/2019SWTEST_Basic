#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N; // 2 <= N <= 10

	/*
	9!은 362880이므로 충분히 2초 내로 돌릴 수 있다
	*/

	vector<int> visitOrder;
	for(int i = 0; i < N; i++) {
		visitOrder.push_back(i);
	}

	int arr[N][N];
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cin >> arr[i][j]; // arr[i][j] <= 1,000,000
		}
	}

	int minCost = 10000001;
	int cost;
	bool impossible;
	do {
		impossible = false;
		cost = 0;
		for(int i = 0; i < N-1; i++) {
			if(arr[visitOrder.at(i)][visitOrder.at(i+1)] == 0) {
				impossible = true;
				break;
			}
			else
				cost += arr[visitOrder.at(i)][visitOrder.at(i+1)];
			
			if(i == N-2) {
				if(arr[visitOrder.at(N-1)][visitOrder.at(0)] == 0) {
					impossible = true;
					break;
				}
				else
					cost += arr[visitOrder.at(N-1)][visitOrder.at(0)];
			}
			
		}
		if(!impossible) {
			if(minCost > cost)
				minCost = cost;
		}
	} while(next_permutation(visitOrder.begin(), visitOrder.end()));

	cout << minCost << '\n';
	return 0;
}