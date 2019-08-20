#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N; // 1 <= N <= 15

	int time[N];
	int price[N];
	for(int i = 0; i < N; i++) {
		cin >> time[i]; // 1 <= time <= 5
		cin >> price[i]; // 1 <= price <= 1000
	}

	int chooseCnt = 1;
	int maxProfit = 0;
	while(chooseCnt <= N) {
		vector<int> schedule;
		for(int i = 0; i < N; i++) {
			if(i < chooseCnt)
				schedule.push_back(1);
			else
				schedule.push_back(0);
		}

		int timeStack;
		int profit;
		do {
			/* print schedule
			for(int i = 0; i < N; i++)
				cout << schedule[i];
			cout << '\n';
			*/

			bool available = true;
			timeStack = 0;
			profit = 0;
			for(int i = 0; i < N; i++) {
				if(schedule[i]) {
					if(timeStack < i+1) {
						//possible
						timeStack = i + time[i];
						if(timeStack > N) {
							available = false;
							break;
						}
						else
							profit += price[i];
					}
					else {
						//impossible
						available = false;
						break;
					}
				}
			}
			if(available) {
				if(maxProfit < profit)
					maxProfit = profit;
			}
		} while(prev_permutation(schedule.begin(), schedule.end()));
		
		chooseCnt++;
	}

	cout << maxProfit << '\n';
	return 0;
}