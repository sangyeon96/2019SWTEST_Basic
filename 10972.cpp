#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N; // 1 <= N <= 10,000

	vector<int> v;
	int tmp;
	for(int i = 0; i < N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	bool result;
	result = next_permutation(v.begin(), v.end());
	if(result == false)
		cout << "-1" << '\n';
	else {
		for(int i = 0; i < N; i++) {
			cout << v[i];
			if(i == N-1)
				cout << '\n';
			else
				cout << " ";
		}
	}


	return 0;
}