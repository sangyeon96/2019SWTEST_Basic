#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N; // 3 <= N <= 8

	vector<int> v;
	int tmp;
	for(int i = 0; i < N; i++) {
		cin >> tmp; // -100 <= tmp <= 100
		v.push_back(tmp);
	}
	sort(v.begin(), v.end()); //오름차순

	int sum;
	int max = 0;
	do {
		sum = 0;
		for(int i = 0; i < N-1; i++) {
			sum += abs(v[i] - v[i+1]);
			if(max < sum)
				max = sum;
		}
	} while(next_permutation(v.begin(), v.end()));

	cout << max << '\n';	
	return 0;
}