#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int k;

	while(1) {
		cin >> k; // 6 < k < 13
		if(k == 0)
			break;

		int arr[k];
		for(int i = 0; i < k; i++)
			cin >> arr[i];

		vector<int> pick;
		int chosen;
		for(int i = 0; i < k; i++) {
			if(i < 6)
				chosen = 1;
			else
				chosen = 0;

			pick.push_back(chosen);
		}

		do {
			for(int i = 0; i < k; i++) {
				if(pick[i] == 1) {
					cout << arr[i] << " ";
				}
				if(i == k-1)
					cout << '\n';
			}
		} while(prev_permutation(pick.begin(), pick.end()));

		cout << '\n';
	}
	return 0;
}