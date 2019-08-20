#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, S;
	cin >> N >> S; // 1 <= N <= 20, |S| <= 1,000,000

	int num[N];
	for(int i = 0; i < N; i++)
		cin >> num[i];

	int plusCnt = 1;
	int caseCnt = 0;
	int sum;
	while(plusCnt <= N) {
		vector<int> testcase;
		for(int i = 0; i < N; i++) {
			if(i < plusCnt)
				testcase.push_back(1);
			else
				testcase.push_back(0);
		}

		do {
			sum = 0;
			for(int i = 0; i < N; i++) {
				if(testcase[i]) {
					sum += num[i];
				}
			}
			if(sum == S)
				caseCnt++;
		} while(prev_permutation(testcase.begin(), testcase.end()));
		plusCnt++;
	}

	cout << caseCnt << '\n';
	return 0;
}