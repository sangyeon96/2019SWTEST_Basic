#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N; // 1 <= N <= 8

	vector<int> v;
	for(int i = 1; i <= N; i++)
		v.push_back(i);

	do {
		for(int i = 0; i < N; i++) {
			cout << v[i];
			if(i == N-1)
				cout << '\n';
			else
				cout << " ";
		}
	} while(next_permutation(v.begin(), v.end()));

	return 0;	
}